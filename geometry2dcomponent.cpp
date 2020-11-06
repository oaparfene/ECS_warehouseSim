#include "geometry2dcomponent.h"

Geometry2DComponent::Geometry2DComponent(Entity* _myEnt, QPolygon* _poly) : Component(_myEnt)
{
    PHYSICS_SYSTEM->geometry2D.insert(this->getID(), _poly);
}
