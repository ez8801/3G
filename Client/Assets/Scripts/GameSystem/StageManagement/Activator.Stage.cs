namespace GameSystem
{
    public partial class Activator
    {
        public static bool CreateInstance(out GameSystem.Stage instance, StageType stageType)
        {
            instance = null;
            switch (stageType)
            {
                case StageType.LobbyStage:
                    instance = new LobbyStage();
                    break;
                case StageType.TitleStage:
                    instance = new TitleStage();
                    break;
                case StageType.GameStage:
                    instance = new GameStage();
                    break;
                case StageType.BattleStage:
                    instance = new BattleStage();
                    break;
            }
            return (instance != null);
        }
    }

}