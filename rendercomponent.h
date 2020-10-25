#ifndef RENDERCOMPONENT_H
#define RENDERCOMPONENT_H

#include "warehousefloor.h"

class RenderComponent : public Qt3DCore::QComponent
{
public:
    RenderComponent(QString _type, float _x, float _y, float _r, QColor _color);// to do: _type to enum
    ~RenderComponent() {};

    QString type;
    float x,y,r;
    QColor color;
};

#endif // RENDERCOMPONENT_H
