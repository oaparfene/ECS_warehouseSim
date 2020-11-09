#include "positioncomponent.h"

PositionComponent::PositionComponent(Entity* _myEnt, QVector2D _pos) : Component(_myEnt)
{
    PhysicsSystem::position.insert(this->getID(), _pos);
}
