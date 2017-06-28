namespace GameSystem
{
    public partial class Activator
    {
        public static bool CreateInstance(out GameSystem.Scene instance, SceneType scenetype)
        {
            instance = null;
            switch (scenetype)
            {
                case SceneType.LobbyScene:
                    instance = new LobbyScene();
                    break;
                case SceneType.TitleScene:
                    instance = new TitleScene();
                    break;
                case SceneType.GameScene:
                    instance = new GameScene();
                    break;
            }
            return (instance != null);
        }
    }

}