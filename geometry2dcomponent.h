#ifndef GEOMETRY2DCOMPONENT_H
#define GEOMETRY2DCOMPONENT_H

#include "component.h"
#include "physicssystem.h"
#include <QPolygonF>

class Geometry2DComponent : public Component
{
public:
    Geometry2DComponent(Entity* _myEnt, QPolygonF* _poly);
};

#endif // GEOMETRY2DCOMPONENT_H
