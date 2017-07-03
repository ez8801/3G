using UnityEditor;
using UnityEngine;
using System.IO;

public class ScriptTemplateProcessor : UnityEditor.AssetModificationProcessor
{
	static string m_ScriptTemplatePath;
	static string ScriptTemplatePath
	{
		get
		{
			if (string.IsNullOrEmpty(m_ScriptTemplatePath))
			{
				string unityExePath = System.Diagnostics.Process.GetCurrentProcess().MainModule.FileName;
				string editorPath = Path.GetDirectoryName(unityExePath);
#if UNITY_IOS
				m_ScriptTemplatePath = string.Concat(editorPath, "/Data/Resources/ScriptTemplates");
#else
				m_ScriptTemplatePath = string.Concat(editorPath, "\\Data\\Resources\\ScriptTemplates\\");
#endif
			}
			return m_ScriptTemplatePath;
		}
	}

	const string JsFile = "80-Javascript-NewBehaviourScript.js.txt";
	const string CsFile = "81-C# Script-NewBehaviourScript.cs.txt";
	const string BooFile = "82-Boo Script-NewBehaviourScript.boo.txt";
	const string ShaderFile = "83-Shader-NewShader.shader.txt";
	const string ComputeFile = "84-Compute Shader-NewComputeShader.compute.txt";

	const string CSharpPath = "ScriptTemplate_CSharp.cs";
	const string JavascriptPath = "ScriptTemplate_JavaScript.js";
	const string BooPath = "ScriptTemplate_Boo.boo";
	const string ShaderPath = "ScriptTemplate_Shader.shader";
	const string ComputeShaderPath = "ScriptTemplate_ComputeShader.compute";

	public static byte[] bom = new byte[3] {
		0xEF,
		0xBB,
		0xBF
	};

	static string m_originCSharp;
	static public string OriginCSharp 
	{
		get
		{
			if (string.IsNullOrEmpty(m_originCSharp))
				m_originCSharp = File.ReadAllText(string.Concat(ScriptTemplatePath, CsFile)); 
			return m_originCSharp; 
		}
	}

	static string m_originJavaScript;
	static public string OriginJavaScript
	{
		get
		{
			if (string.IsNullOrEmpty(m_originJavaScript))
				m_originJavaScript = File.ReadAllText(string.Concat(ScriptTemplatePath, JsFile));
			return m_originJavaScript;
		}
	}

	static string m_originBoo;
	static public string OriginBoo
	{
		get
		{
			if (string.IsNullOrEmpty(m_originBoo))
				m_originBoo = File.ReadAllText(string.Concat(ScriptTemplatePath, BooFile));
			return m_originBoo;
		}
	}

	static string m_originShader;
	static public string OriginShader
	{
		get
		{
			if (string.IsNullOrEmpty(m_originShader))
				m_originShader = File.ReadAllText(string.Concat(ScriptTemplatePath, ShaderFile));
			return m_originShader;
		}
	}

	static string m_originComputeShader;
	static public string OriginComputeShader
	{
		get
		{
			if (string.IsNullOrEmpty(m_originComputeShader))
				m_originComputeShader = File.ReadAllText(string.Concat(ScriptTemplatePath, ComputeFile));
			return m_originComputeShader;
		}
	}

	static public string CSharp { get { return GetScript(CSharpPath); } }
	static public string JavaScript { get { return GetScript(JavascriptPath); } }
	static public string Boo { get { return GetScript(BooPath); } }
	static public string Shader { get { return GetScript(ShaderPath); } }
	static public string ComputeShader { get { return GetScript(ComputeShaderPath); } }

	static string GetScript(string path)
	{
		if (string.IsNullOrEmpty(path))
            return string.Empty;

		var scriptResource = Resources.Load<TextAsset>(path);
		return (scriptResource == null) ? string.Empty : scriptResource.text;
	}
    
    public static void OnWillCreateAsset(string path)
    {
		string assetPath = path.Replace(".meta", string.Empty);
		string fileName = Path.GetFileNameWithoutExtension(assetPath);
		string extension = Path.GetExtension(assetPath);
		string templateScript = null;

		switch(extension)
		{
            case ".cs":
                if (IsNewScript(fileName, "#SCRIPTNAME#", File.ReadAllText(assetPath), OriginCSharp))
                    templateScript = CSharp;
                break;
            case ".js":
				if (IsNewScript(fileName, "#SCRIPTNAME#", File.ReadAllText(assetPath), OriginJavaScript))
					templateScript = JavaScript;
				break;
			case ".boo":
				if (IsNewScript(fileName, "#SCRIPTNAME#", File.ReadAllText(assetPath), OriginBoo))
					templateScript = Boo;
				break;
			case ".shader":
				if (IsNewScript(fileName, "#NAME#", File.ReadAllText(assetPath), OriginShader))
					templateScript = Shader;
				break;
			case ".compute":
				if (IsNewScript(fileName, "#NAME#", File.ReadAllText(assetPath), OriginComputeShader))
					templateScript = ComputeShader;
				break;
		}

		if (string.IsNullOrEmpty(templateScript))
			return;

		string creationDate = System.DateTime.Now.ToString("yyyy-MM-dd");
		templateScript = templateScript.Replace("#WRITER_NAME#", System.Environment.UserName);
		templateScript = templateScript.Replace("#CREATION_DATE#", creationDate);        
		templateScript = templateScript.Replace("#PROJECT_NAME#", GameDefine.ProductName); // PlayerSettings.productName
        templateScript = templateScript.Replace("#SMART_DEVELOPERS#", GameDefine.CompanyName); // PlayerSettings.companyName
        templateScript = templateScript.Replace("#SCRIPT_NAME#", fileName);

		byte[] bytes = System.Text.Encoding.UTF8.GetBytes(templateScript);
        
		// 서명 있는
		if (IsExistsBom(ref bytes) == false)
		{
            byte[] newBytes = new byte[bytes.Length + bom.Length];
            System.Array.Copy(bom, newBytes, bom.Length);
            System.Array.Copy(bytes, 0, newBytes, bom.Length, bytes.Length);
			File.WriteAllBytes(assetPath, newBytes);
		}
		else
		{
			File.WriteAllText(assetPath, templateScript);
		}
		AssetDatabase.Refresh();
    }

	private static bool IsExistsBom(ref byte[] i_bytes)
	{
		if (i_bytes[0] == bom[0]
		    && i_bytes[1] == bom[1]
		    && i_bytes[2] == bom[2])
		{
			return true;
		}
		return false;
	}
    
	static public bool IsNewScript(string fileName, string scriptDefine, string currentDesc, string originTemplate)
	{
		string compareScript = originTemplate.Replace(scriptDefine, fileName);
        compareScript = compareScript.Replace("#NOTRIM#", string.Empty);
		return compareScript.Equals(currentDesc);
	}
}