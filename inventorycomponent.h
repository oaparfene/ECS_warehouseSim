#ifndef INVENTORYCOMPONENT_H
#define INVENTORYCOMPONENT_H

#include "component.h"
#include "brainsystem.h"

class InventoryComponent : public Component
{
public:
    InventoryComponent(Entity* _myEnt, QVector<uint> _inv);
};

#endif // INVENTORYCOMPONENT_H
