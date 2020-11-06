#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <QGlobalStatic>
#include <QMultiHash>
#include <QPointF>
#include <QVector>

#include "warehousefloor.h"


class RenderComponent;

class RenderSystem
{
public:
    RenderSystem();
    void simulate();
    QPainter* p;
    QList<RenderComponent*> comps;

    //

    QMultiHash<uint, QPointF*> points;
};

Q_GLOBAL_STATIC(RenderSystem, RENDER_SYSTEM)

#endif // RENDERSYSTEM_H
