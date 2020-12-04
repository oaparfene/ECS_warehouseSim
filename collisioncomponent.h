#ifndef COLLISIONCOMPONENT_H
#define COLLISIONCOMPONENT_H

#include "component.h"
#include "physicssystem.h"

class CollisionComponent : public Component
{
public:
    CollisionComponent(Entity* _myEnt);
};

#endif // COLLISIONCOMPONENT_H
