#include <Server/System/Damage.hh>

#include <Server/Component/Life.hh>
#include <Server/Component/Physical.hh>
#include <Server/Simulation.hh>

namespace app::system
{
    Damage::Damage(Simulation &simulation)
        : m_Simulation(simulation)
    {
    }

    void Damage::Tick()
    {
        m_Simulation.ForEachEntity([&](Entity entity)
                                   {
            if (!m_Simulation.HasComponent<component::Physical>(entity))
                return;
            component::Physical &physical = m_Simulation.Get<component::Physical>(entity);
            component::Life &life = m_Simulation.Get<component::Life>(entity);
            component::Basic &basic = m_Simulation.Get<component::Basic>(entity);
            for (Entity i = 0; i < physical.m_Collisions.size(); i++)
            {
                Entity other = physical.m_Collisions[i];
                if (!m_Simulation.HasComponent<component::Life>(other))
                    continue;
                component::Life &life2 = m_Simulation.Get<component::Life>(other);
                component::Basic &basic2 = m_Simulation.Get<component::Basic>(other);
                if (basic.Team() == basic2.Team())
                    continue;
                life.Health(life.Health() - life2.Damage());
                life2.Health(life2.Health() - life.Damage());

                // TODO: delete entity
            } });
    }

    void Damage::PostTick()
    {
    }
}
