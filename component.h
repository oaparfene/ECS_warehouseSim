#ifndef COMPONENT_H
#define COMPONENT_H

#include <QtGlobal>

class Entity;

class Component
{
public:
    Component(Entity* _myEnt);
    virtual ~Component() {};
    uint getID() const;
    Entity* getEntity() const;

private:
    Entity* myEnt;
    uint ID; //same ID as entity it belongs to
};

#endif // COMPONENT_H
