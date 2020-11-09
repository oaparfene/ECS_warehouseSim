#ifndef VELOCITYCOMPONENT_H
#define VELOCITYCOMPONENT_H

#include "component.h"
#include "physicssystem.h"

class VelocityComponent : public Component
{
public:
    VelocityComponent(Entity* _myEnt, Velocity _velocity);
};

#endif // VELOCITYCOMPONENT_H
