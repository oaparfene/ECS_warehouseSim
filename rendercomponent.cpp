#include "rendercomponent.h"

RenderComponent::RenderComponent(Entity* _myEnt, QPolygon* _poly) : Component(_myEnt)
{
    RenderSystem::points.insert(this->getID(), _poly);
    qDebug() << (*RenderSystem::points.find(this->getID()).value());
    //qDebug() <<  RenderSystem::points.size();
}
