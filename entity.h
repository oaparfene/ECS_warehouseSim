#ifndef ENTITY_H
#define ENTITY_H

#include <QtGlobal>
#include <QVector>

#include "component.h"

class Entity
{
public:
    Entity();
    uint getID() const;
    uint getEntityCount() const;
    QVector<Component*> getComponentVector() const;
    void addComponent(Component* _comp);
private:
    uint ID;
    static uint entityCount;
    QVector<Component*> componentVector;
};

#endif // ENTITY_H
