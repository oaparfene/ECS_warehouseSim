#include "mulecomponent.h"

MuleComponent::MuleComponent(Entity* _myEnt) : Component(_myEnt)
{
    BrainSystem::mule.insert(this->getID(), QVector<uint>());
}
