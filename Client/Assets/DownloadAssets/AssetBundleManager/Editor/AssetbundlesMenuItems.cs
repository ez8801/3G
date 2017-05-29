using UnityEditor;

namespace AssetBundles
{
	public class AssetBundlesMenuItems
	{
		const string kSimulationMode = "Assets/AssetBundles/Simulation Mode";
	
		[MenuItem(kSimulationMode)]
		public static void ToggleSimulationMode()
		{
			AssetBundleManager.SimulateAssetBundleInEditor = !AssetBundleManager.SimulateAssetBundleInEditor;
		}
	
		[MenuItem(kSimulationMode, true)]
		public static bool ToggleSimulationModeValidate()
		{
			Menu.SetChecked(kSimulationMode, AssetBundleManager.SimulateAssetBundleInEditor);
			return true;
		}
		
		[MenuItem ("Build/Build AssetBundles")]
		static public void BuildAssetBundles()
		{
			BuildScript.BuildAssetBundles();
		}

        [MenuItem("Build/Build APK")]
        static public void BuildAndroid()
        {

        }

        [MenuItem("Build/Build IPA")]
        static public void BuildIOS()
        {

        }
	}
}