#ifndef COMPONENT_H
#define COMPONENT_H

#include <QtGlobal>

class Entity;

class Component
{
public:
    Component(Entity* _myEnt);
    uint getID() const;
    Entity* getEntity() const;

private:
    Entity* myEnt;
    uint ID;
};

#endif // COMPONENT_H
