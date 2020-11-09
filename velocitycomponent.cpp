#include "velocitycomponent.h"

VelocityComponent::VelocityComponent(Entity* _myEnt, Velocity _velocity) : Component(_myEnt)
{
    PhysicsSystem::velocity.insert(this->getID(), _velocity);
}
