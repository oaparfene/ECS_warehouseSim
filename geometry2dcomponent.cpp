#include "geometry2dcomponent.h"

Geometry2DComponent::Geometry2DComponent(Entity* _myEnt, QPolygonF* _poly) : Component(_myEnt)
{
    PhysicsSystem::geometry2D.insert(this->getID(), *_poly);
}
