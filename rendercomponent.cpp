#include "rendercomponent.h"

RenderComponent::RenderComponent(Entity* _myEnt, Appearance _appearance) : Component(_myEnt)
{
    RenderSystem::appearance.insert(this->getID(), _appearance);
    //qDebug() << (*RenderSystem::poly.find(this->getID()).value());
    //qDebug() <<  RenderSystem::poly.size();
}

RenderComponent::~RenderComponent()
{
    RenderSystem::appearance.erase(RenderSystem::appearance.find(this->getID()));

}
