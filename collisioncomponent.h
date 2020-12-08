#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H

#include "component.h"
#include "physicssystem.h"

class CollisionComponent : public Component
{
public:
    CollisionComponent(Entity* _myEnt, bool _collision);
};

#endif // COLLISIONCOMPONENT_H
