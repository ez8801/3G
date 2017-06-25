
public class Actor : MovingEntity
{
    private StateMachine m_stateMachine;

    public virtual Stats Stats { get { return null; } }

    protected float m_currentHp;
    public float CurrentHp
    {
        get
        {
            return m_currentHp;
        }
    }

    public bool IsAlive
    {
        get
        {
            return (m_currentHp > 0f);
        }
    }

    private Team m_team = null;

    public void JoinTo(Team team)
    {
        m_team = team;
        m_team.AddMember(this);
    }
}
