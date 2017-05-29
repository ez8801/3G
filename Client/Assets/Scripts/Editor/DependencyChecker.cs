using UnityEngine;
using UnityEditor;
using System.Collections.Generic;
using System.IO;

/// <summary>
/// Asset(Script, Material, Prefab...)의 Dependency를 체크하는데 사용됩니다.
/// </summary>
public class DependencyChecker : EditorWindow
{
	private Object m_sourceObject = null;
	private Object[] m_sourceFolders = new Object[1] { null };
	private int m_folderCount = 1;
	private List<Object> m_searchResults = new List<Object>();

	private Vector2 m_scrollPos = Vector2.zero;


	[MenuItem("Tools/Dependency Checker %F1", false, 1)]
	public static void OpenDependencyChecker()
	{
		GetWindow(typeof(DependencyChecker));
	}

	private void DrawMenuBar()
	{
		// Source Object
		EditorGUILayout.BeginHorizontal();
		{
			EditorGUILayout.LabelField("Object", GUILayout.Width(80));
			m_sourceObject = EditorGUILayout.ObjectField(m_sourceObject, typeof(UnityEngine.Object), false);
		}
		EditorGUILayout.EndHorizontal();

		// Folder Count
		EditorGUILayout.BeginHorizontal();
		{ 
			EditorGUILayout.LabelField("Folder Count", GUILayout.Width(80));
			int folderCount = EditorGUILayout.IntField(m_folderCount);
			if (m_folderCount != folderCount)
			{
				EnsureCapacity(folderCount);
			}
		}
		EditorGUILayout.EndHorizontal();

		// Folder List
		for (int i = 0; i < m_folderCount; ++i)
		{
			EditorGUILayout.BeginHorizontal();
			{ 
				EditorGUILayout.LabelField(string.Format("Folder {0}", i), GUILayout.Width(80));
				m_sourceFolders[i] = EditorGUILayout.ObjectField(m_sourceFolders[i], typeof(UnityEngine.Object), false);
			}
			EditorGUILayout.EndHorizontal();
		}

		// Search Button
		if (GUILayout.Button("검색") == true)
			Search();

        if (GUILayout.Button("모두 적용") == true)
            ApplyAll();
    }

	private void DrawSearchResult()
	{
		if (m_searchResults.Count == 0)
		{
			EditorGUILayout.LabelField("해당 내용이 없습니다", GUILayout.ExpandWidth(true));
		}
		else
		{
			foreach (Object each in m_searchResults)
			{
				EditorGUILayout.ObjectField(each, typeof(Object), false);
			}
		}
	}

	void OnGUI()
	{
		m_scrollPos = EditorGUILayout.BeginScrollView(m_scrollPos);

		EditorGUILayout.BeginVertical();
		{
			DrawMenuBar();
			DrawSearchResult();
		}
		EditorGUILayout.EndVertical();

		GUILayout.EndScrollView();
	}

	private void DisplayDialog(string i_strTitle, string i_strMsg, string i_strOK)
	{
#if UNITY_EDITOR
		EditorUtility.DisplayDialog(i_strTitle, i_strMsg, i_strOK);
#endif
	}


	private void EnsureCapacity(int newCount)
	{
		Object[] oNewFolders = new Object[newCount];
		for (int i = 0; i < newCount; ++i)
		{
			if (i < m_folderCount)
				oNewFolders[i] = m_sourceFolders[i];
			else
				oNewFolders[i] = null;
		}

		m_folderCount = newCount;
		m_sourceFolders = oNewFolders;
	}

    private void ApplyAll()
    {
        if (m_sourceObject == null)
            return;

        if (m_searchResults == null || m_searchResults.Count == 0)
            return;

        for (int i = 0; i < m_searchResults.Count; i++)
        {
            Object each = m_searchResults[i];
            if (m_sourceObject.name == each.name)
                continue;

            SavePrefab(each as GameObject);
        }
    }

    public static void SavePrefab(GameObject obj)
    {
        PrefabType prefabType = PrefabUtility.GetPrefabType(obj);
        if (prefabType != PrefabType.Prefab)
        {
            return;
        }

        GameObject go = Instantiate(obj) as GameObject;
        
        NestedPrefab nestedPrefab = go.GetComponent<NestedPrefab>();
        if (nestedPrefab != null)
        {
            string prevName = string.Empty;
            if (nestedPrefab.m_instance != null)
            {
                prevName = nestedPrefab.m_instance.name;
            }
            nestedPrefab.InstantiateObject();
            if (string.IsNullOrEmpty(prevName) == false)
                nestedPrefab.m_instance.name = prevName;
        }

        PrefabUtility.ReplacePrefab(go
                , obj
                , ReplacePrefabOptions.ConnectToPrefab);

        DestroyImmediate(go);
        go = null;
    }

    private void Search()
	{
		m_searchResults.Clear();

		if (m_sourceObject == null)
		{
			DisplayDialog("Error", "검색할 Object가 지정되지 않았습니다.", "확인");
			return;
		}

		if (m_sourceFolders == null || m_sourceFolders.Length <= 0)
		{
			DisplayDialog("Error", "검색할 폴더가 지정되지 않았습니다.", "확인");
			return;
		}

		bool isExistsValidFolder = System.Array.Exists(m_sourceFolders, (match) => {
			return (match != null);
		});

		if (isExistsValidFolder == false)
		{
			DisplayDialog("Error", "검색할 폴더가 지정되지 않았습니다.", "확인");
			return;
		}

		for (int i = 0; i < m_folderCount; ++i)
		{
			if (m_sourceFolders[i] == null) 
				continue;

			string strFolder = Path.GetDirectoryName(AssetDatabase.GetAssetPath(m_sourceFolders[i])) + "/" + m_sourceFolders[i].name;
			if (Directory.Exists(strFolder) == false)
			{
				DisplayDialog("Error", "검색할 폴더가 지정되지 않았습니다.", "확인");
				return;
			}
			string strSourcePath = AssetDatabase.GetAssetPath(m_sourceObject).Replace("\\", "/").ToLower();

			string[] strAssets = GetExtFiles(strFolder, "*.prefab", SearchOption.AllDirectories);
			for (int j = 0; j < strAssets.Length; ++j)
			{
				float progress = (j == 0) ? 0f : (float) j / strAssets.Length;
				bool isCancel = EditorUtility.DisplayCancelableProgressBar("Searching"
				                                                           , string.Format("{0:F0}% ({1} | {2})", progress * 100, j, strAssets.Length)
				                                                           , progress);
				if (isCancel)
				{
					break;
				}

				string[] strDependencies = AssetDatabase.GetDependencies(new string[] { strAssets[j] });
				if (System.Array.FindIndex(strDependencies, match => { return (match.Replace ("\\", "/").ToLower () == strSourcePath);}) >= 0)
				{
					Object oObj = AssetDatabase.LoadAssetAtPath(strAssets[j], typeof(Object));
					if (oObj != null)
						m_searchResults.Add(oObj);
				}
			}
		}

		EditorUtility.ClearProgressBar();
	}

	public string[] GetExtFiles(string path, string extensions, System.IO.SearchOption searchOption)
	{
		List<string> lstFile = new List<string>();
		
		string [] exts = extensions.Split('|');
		
		for (int index = 0; index < exts.Length; index++)
		{
			string [] files = Directory.GetFiles(path, exts[index], searchOption);
			lstFile.AddRange(files);
		}
		return lstFile.ToArray();
	}
}
