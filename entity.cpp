#include "entity.h"

uint Entity::entityCount = 0;

Entity::Entity()
{
    ID = ++entityCount;
}

Entity::~Entity()
{
    while (!componentVector.isEmpty())
    {
        delete componentVector.begin();
    }
}

uint Entity::getID() const
{
    return ID;
}

uint Entity::getEntityCount() const
{
    return entityCount;
}

QVector<Component*> Entity::getComponentVector() const
{
    return componentVector;
}

void Entity::addComponent(Component* _comp)
{
    componentVector.push_back(_comp);
}
