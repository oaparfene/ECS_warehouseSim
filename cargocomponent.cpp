#include "cargocomponent.h"

CargoComponent::CargoComponent(Entity* _myEnt) : Component (_myEnt)
{
    BrainSystem::cargo.insert(this->getID(), true);
}
