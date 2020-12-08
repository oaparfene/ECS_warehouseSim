#ifndef ENTITY_H
#define ENTITY_H

#include <QtGlobal>
#include <QVector>

#include "component.h"

class Entity
{
public:
    Entity();
    ~Entity();
    uint getID() const;
    uint getEntityCount() const;
    QVector<Component*> getComponentVector() const;
    void addComponent(Component* _comp);
    static void deleteEntByID(uint _id);
private:
    uint ID;
    static uint entityCount;
    static QVector<Entity*> entityVector;
    QVector<Component*> componentVector;
};

#endif // ENTITY_H
