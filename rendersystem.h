#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include "warehousefloor.h"
#include "rendercomponent.h"

class RenderComponent;

class RenderSystem
{
public:
    RenderSystem();
    void simulate();
    QPainter* p;
    QList<RenderComponent*> comps;
};

#endif // RENDERSYSTEM_H
