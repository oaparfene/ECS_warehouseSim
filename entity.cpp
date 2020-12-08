#include "entity.h"

uint Entity::entityCount = 0;
QVector<Entity*> Entity::entityVector = QVector<Entity*>();

Entity::Entity()
{
    ID = ++entityCount;
    entityVector.append(this);
}

Entity::~Entity()
{
    qDeleteAll(componentVector.begin(), componentVector.end());
    componentVector.clear();
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

void Entity::deleteEntByID(uint _id)
{
    QVector<Entity*>::iterator i;
    for (i = entityVector.begin() ; i != entityVector.end() ; i++)
    {
        if ((*i)->getID() == _id)
        {
            delete *i;
            break;
        }
    }
}
