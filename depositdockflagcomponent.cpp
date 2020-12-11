#include "depositdockflagcomponent.h"

DepositDockFlagComponent::DepositDockFlagComponent(Entity* _myEnt) : Component(_myEnt)
{
    BrainSystem::depositDocks.insert(this->getID(), true);
}

DepositDockFlagComponent::~DepositDockFlagComponent()
{

}
