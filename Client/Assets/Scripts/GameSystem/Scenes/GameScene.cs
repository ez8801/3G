
using System.Collections;

public class GameScene : GameSystem.Scene, IObserver
{
    public const string LevelName = "Game";

    private ConditionCompositer m_loseCondition = new ConditionCompositer();
    private ConditionCompositer m_winCondition = new ConditionCompositer();

    private Actor m_player;

    private Team m_playerTeam;
    private Team m_monsterTeam;

    public override IEnumerator OnCrate(Intent savedInstanceState)
    {
        NotificationCenter.Instance.AddObserver(this);

        m_playerTeam = Team.AddTeam(1, "Player.Team");
        m_monsterTeam = Team.AddTeam(2, "Monster.Team");

        m_player = (Actor) CharacterFactory.CreateEntity("Prefabs/Character/Player");
        m_player.JoinTo(m_playerTeam);

        m_loseCondition.AddCondition(new HpCondition(m_player, CompareOperation.LessThanOrEqual, 0f));
        m_winCondition.AddCondition(new TotalDestruction(m_monsterTeam));

        yield return null;
    }
    
    public void HandleNotification(Notification notification)
    {
        switch (notification.id)
        {
            case (int)Notification.Entity.OnDead:
                
                break;
        }
    }

    public override void OnStop()
    {
        base.OnStop();
        NotificationCenter.Instance.RemoveObserver(this);
    }
}
