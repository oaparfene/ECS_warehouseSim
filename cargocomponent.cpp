#include "cargocomponent.h"

CargoComponent::CargoComponent(Entity* _myEnt) : Component (_myEnt)
{
    BrainSystem::cargo.insert(this->getID(), true);
}

CargoComponent::~CargoComponent()
{
    BrainSystem::cargo.erase(BrainSystem::cargo.find(this->getID()));
}
