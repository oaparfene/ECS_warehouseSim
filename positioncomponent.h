#ifndef POSITIONCOMPONENT_H
#define POSITIONCOMPONENT_H

#include <QVector2D>
#include "physicssystem.h"
#include "component.h"

class PositionComponent : public Component
{
public:
    PositionComponent(Entity* _myEnt, QVector2D _pos);
};

#endif // POSITIONCOMPONENT_H
