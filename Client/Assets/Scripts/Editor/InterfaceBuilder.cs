using System.Collections.Generic;
using UnityEngine;
using UnityEditor;
using System.IO;
using System.Text;

public class InterfaceBuilder : EditorWindow
{
    private static InterfaceBuilder m_window = null;
    private string className = string.Empty;
    private Object destinationFolder = null;

    private List<Variable> m_includes = new List<Variable>();
    private List<Variable> m_excludes = new List<Variable>();

    private float m_halfWidth = 0f;
    private Vector2 m_scrollPosition = Vector2.zero;

    public struct Variable
    {
        public string customName;
        public string fullPath;
        public Object @object;
        public int selectedIndex;
        public string[] components;
    }

    public void Initialize(Transform selection)
    {
        if (selection == null)
            return;

        m_includes.Clear();

        Transform[] transforms = selection.GetComponentsInChildren<Transform>();
        for (int i = 0; i < transforms.Length; i++)
        {
            Transform each = transforms[i];
            
            Component[] components = each.GetComponents(typeof(Component));
            List<string> componentNames = new List<string>();
            for (int j = 0; j < components.Length; j++)
            {
                Component component = components[j];
                if (component == null)
                    continue;

                componentNames.Add(component.GetType().Name);
            }
            
            m_includes.Add(new Variable()
            {
                customName = each.name,
                fullPath = each.GetFullPath(selection),
                @object = each,
                selectedIndex = (componentNames.Count > 1) ? 1 : 0,
                components = componentNames.ToArray()
            });
        }
    }

    [MenuItem("Tools/Interface Builder %F2", false, 2)]
    static public void Open()
    {
        m_window = GetWindow<InterfaceBuilder>(false, "Interface Builder", true);
    }

    private void DrawView(List<Variable> list, string buttonName, System.Action<int> action)
    {
        EditorGUILayout.BeginVertical(GUILayout.Width(m_halfWidth), GUILayout.MaxWidth(m_halfWidth));
        if (list.Count > 0)
        {
            for (int i = 0; i < list.Count; i++)
            {
                GUILayout.BeginHorizontal();
                {
                    Variable each = list[i];
                    EditorGUILayout.ObjectField(each.@object, typeof(Object), true, GUILayout.Width(96f));
                    int selectedIndex = EditorGUILayout.Popup(each.selectedIndex, each.components, GUILayout.Width(96f));
                    if (selectedIndex != each.selectedIndex)
                    {
                        each.selectedIndex = selectedIndex;
                        list[i] = each;
                    }

                    string customName = GUILayout.TextField(each.customName, GUILayout.Width(96f));
                    if (!string.IsNullOrEmpty(customName) && customName != each.customName)
                    {
                        each.customName = customName;
                        list[i] = each;
                    }

                    if (GUILayout.Button(buttonName, GUILayout.MaxWidth(46f)))
                    {
                        action(i);
                        break;
                    }

                    if (GUILayout.Button("Copy", GUILayout.MaxWidth(52f)))
                    {
                        EditorGUIUtility.systemCopyBuffer = each.fullPath;
                    }
                }
                GUILayout.EndHorizontal();
            }
        }
        else
        {
            GUILayout.Label("Empty", GUILayout.ExpandWidth(true), GUILayout.ExpandHeight(true));
        }
            
        EditorGUILayout.EndVertical();
    }

    private void OnGUI()
    {
        if (m_window == null)
        {
            Open();
            return;
        }

        //
        if (GUILayout.Button("Initialize"))
        {
            Initialize(Selection.activeTransform);
        }

        //
        EditorGUILayout.BeginHorizontal();
        {
            GUILayout.Label("Script Name", GUILayout.MaxWidth(108f));
            className = GUILayout.TextField(className);
        }
        EditorGUILayout.EndHorizontal();

        //
        EditorGUILayout.BeginHorizontal();
        {
            GUILayout.Label("Save As", GUILayout.MaxWidth(108f));
            destinationFolder = EditorGUILayout.ObjectField(destinationFolder, typeof(Object), true);
        }
        EditorGUILayout.EndHorizontal();
        
        //
        GUILayout.Label(string.Format("Includes: {0}, Excludes: {1}", m_includes.Count, m_excludes.Count));
        
        //
        GUILayout.BeginHorizontal();
        if (GUILayout.Button("Exclude All", GUILayout.ExpandWidth(true)))
        {
            for (int i = 0; i < m_includes.Count; i++)
            {
                m_excludes.Add(m_includes[i]);
            }
            m_includes.Clear();
        }

        if (GUILayout.Button("Include All", GUILayout.ExpandWidth(true)))
        {
            for (int i = 0; i < m_excludes.Count; i++)
            {
                m_includes.Add(m_excludes[i]);
            }
            m_excludes.Clear();
        }
        GUILayout.EndHorizontal();

        m_scrollPosition = EditorGUILayout.BeginScrollView(m_scrollPosition, false, true);

        m_halfWidth = m_window.position.width * 0.5f;

        //
        EditorGUILayout.BeginHorizontal();
        {
            DrawView(m_includes, "X", (i) =>
            {
                Variable exclude = m_includes[i];
                m_includes.RemoveAt(i);
                m_excludes.Add(exclude);

                GUILayout.EndHorizontal();
            });

            DrawView(m_excludes, "<", (i) =>
            {
                Variable exclude = m_excludes[i];
                m_excludes.RemoveAt(i);
                m_includes.Add(exclude);

                GUILayout.EndHorizontal();
            });
        }        
        EditorGUILayout.EndHorizontal();

        EditorGUILayout.EndScrollView();
        
        //
        if (GUILayout.Button("Generate"))
        {
            if (m_includes.Count == 0)
                return;

            if (destinationFolder == null)
            {
                EditorUtility.DisplayDialog("Message", "폴더를 지정해주세요.", "OK");
                return;
            }

            string assetPath = AssetDatabase.GetAssetPath(destinationFolder);
            string directoryName = Path.GetDirectoryName(assetPath + "/" + destinationFolder.name);
            if (Directory.Exists(directoryName) == false)
            {
                EditorUtility.DisplayDialog("Message", "폴더를 찾을 수 없습니다.", "OK");
                return;
            }

            StringBuilder builder = new StringBuilder();
            builder.AppendLine("using UnityEngine;");
            builder.AppendLine();
            builder.AppendFormat("public class {0} : MonoBehaviour", className);
            builder.AppendLine();
            builder.AppendLine("{");
            {
                // View Definition
                builder.AppendLine("\t[System.Serializable]");
                builder.AppendLine("\tpublic struct View");
                builder.AppendLine("\t{");
                for (int i = 0; i < m_includes.Count; i++)
                {
                    Variable each = m_includes[i];
                    builder.AppendFormat("\t\tpublic {0} {1};", each.components[each.selectedIndex], each.customName);
                    builder.AppendLine();
                }
                builder.AppendLine("\t}");
                
                builder.AppendLine("\tpublic View m_view;");
                builder.AppendLine();

                builder.AppendLine("[ContextMenu(\"Bind\")]");
                builder.AppendLine("\tpublic void Initialize()");
                builder.AppendLine("\t{");
                builder.AppendLine("\t\tm_view = new View();");
                
                for (int i = 0; i < m_includes.Count; i++)
                {
                    Variable each = m_includes[i];
                    builder.AppendFormat("\t\tthis.Bind(ref m_view.{0}, \"{1}\");", each.customName, each.fullPath);
                    builder.AppendLine();
                }

                builder.AppendLine("\t}");
            }
            builder.AppendLine("}");

            string destinationPath = Path.Combine(directoryName, string.Concat(className, ".cs"));
            FileStream fs = null;
            if (!File.Exists(destinationPath))
                fs = File.Create(destinationPath);
            else
                fs = File.Open(destinationPath, FileMode.OpenOrCreate);

            using (StreamWriter sw = new StreamWriter(fs, Encoding.UTF8))
            {
                using (StringReader sr = new StringReader(builder.ToString()))
                {
                    while (sr.Peek() != -1)
                    {
                        sw.WriteLine(sr.ReadLine());
                    }

                    sw.Flush();
                }
            }

            AssetDatabase.Refresh();
        }
    }
}
