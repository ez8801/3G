public partial class Activator
{
	public static bool CreateInstance(ref GameSystem.Scene scene, SceneType scenetype) {
		GameSystem.Scene instance = null;
		switch (scenetype) {
			case SceneType.LobbyScene:
				instance = new LobbyScene();
				break;
			case SceneType.TitleScene:
				instance = new TitleScene();
				break;
		}
		return (instance != null);
	}
}
