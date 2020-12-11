#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include "component.h"
#include "rendersystem.h"

class RenderComponent : public Component
{
public:
    RenderComponent(Entity* _myEnt, Appearance _appearance);
    ~RenderComponent();
};

#endif // RENDERCOMPONENT_H
