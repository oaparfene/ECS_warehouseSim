#include "collisioncomponent.h"

CollisionComponent::CollisionComponent(Entity* _myEnt, bool _collision) : Component(_myEnt)
{
    PhysicsSystem::collisionMask.insert(this->getID(), _collision);
}
