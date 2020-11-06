#include "rendercomponent.h"

RenderComponent::RenderComponent(Entity* _myEnt, QPointF* _points) : Component(_myEnt)
{
    RENDER_SYSTEM->points.insert(this->getID(), _points);
    qDebug() << (*RENDER_SYSTEM->points.find(this->getID()).value());
    qDebug() <<  RENDER_SYSTEM->points.size();
}
