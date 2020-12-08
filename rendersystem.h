#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <QHash>
#include <QPointF>
#include <QVector>

#include "warehousefloor.h"

struct Appearance
{
    QPolygonF* polygon;
    QColor color;
};

class RenderComponent;

class RenderSystem
{
public:
    RenderSystem();
    static void simulate();
    static QPainter* p;
    static QHash<uint, Appearance> appearance;
};

#endif // RENDERSYSTEM_H
