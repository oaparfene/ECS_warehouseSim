#include "inventorycomponent.h"

InventoryComponent::InventoryComponent(Entity* _myEnt, QVector<uint> _inv) : Component(_myEnt)
{
    BrainSystem::inventory.insert(this->getID(), _inv);
}
