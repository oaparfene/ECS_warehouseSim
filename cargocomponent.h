#ifndef CARGOCOMPONENT_H
#define CARGOCOMPONENT_H

#include "component.h"
#include "brainsystem.h"

class CargoComponent : public Component
{
public:
    CargoComponent(Entity* _myEnt);
    ~CargoComponent();
};

#endif // CARGOCOMPONENT_H
