#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <QGlobalStatic>
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
    static QList<RenderComponent*> comps;
    static QHash<uint, Appearance> appearance;
};

//Q_GLOBAL_STATIC(RenderSystem, RENDER_SYSTEM)

#endif // RENDERSYSTEM_H
