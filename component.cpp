#include "component.h"
#include "entity.h"

Component::Component(Entity* _myEnt)
{
    myEnt = _myEnt;
    ID = myEnt->getID();
}

uint Component::getID() const
{
    return ID;
}

Entity* Component::getEntity() const
{
    return myEnt;
}
