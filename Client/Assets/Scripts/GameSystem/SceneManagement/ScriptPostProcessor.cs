using System;
using System.IO;
using System.Collections.Generic;
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
        string scriptPath = Path.Combine(Application.dataPath, "Scripts/GameSystem/SceneManagement/SceneType.cs");
        if (EnumGenerator.GenerateEnum(scriptPath, typeof(GameSystem.Scene), typeof(SceneType)))
        {
            AssetDatabase.Refresh();

            GenerateActivetor();
        }
    }

    [MenuItem("Code/Generate Activator")]
    private static void GenerateActivetor()
    {
        string scriptPath = Path.Combine(Application.dataPath, "Scripts/GameSystem/SceneManagement/Activator.cs");
        EnumGenerator.GenerateActivator(scriptPath, typeof(GameSystem.Scene), typeof(SceneType));
    }
}
