using System.IO;
using UnityEngine;
using UnityEditor;

public class ScriptPostProcessor : AssetPostprocessor
{
    static void OnPostprocessAllAssets(string[] importedAssets
        , string[] deletedAssets
        , string[] movedAssets
        , string[] movedFromAssetPaths)
    {
        //
    }
    
    [UnityEditor.Callbacks.DidReloadScripts]
    [MenuItem("Code/Generate Enum")]
    private static void GenerateEnum()
    {
        string scriptPath = Path.Combine(Application.dataPath, "Scripts/GameSystem/StageManagement/StageType.cs");
        if (EnumGenerator.GenerateEnum(scriptPath, typeof(GameSystem.Stage), typeof(StageType)))
        {
            AssetDatabase.Refresh();

            GenerateActivetor();
        }
    }

    [MenuItem("Code/Generate Activator")]
    private static void GenerateActivetor()
    {
        string scriptPath = Path.Combine(Application.dataPath, "Scripts/GameSystem/StageManagement/Activator.cs");
        EnumGenerator.GenerateActivator(scriptPath, typeof(GameSystem.Stage), typeof(StageType));
    }
}
