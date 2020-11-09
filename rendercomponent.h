#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include "component.h"
#include "rendersystem.h"

class RenderComponent : public Component//public Qt3DCore::QComponent
{
public:
    //RenderComponent(QString _type, float _x, float _y, float _r, QColor _color);// to do: _type to enum
    RenderComponent(Entity* _myEnt, Appearance _appearance);
    ~RenderComponent() {};

    //QString type;
    //float x,y,r;
    //QColor color;
};

#endif // RENDERCOMPONENT_H
