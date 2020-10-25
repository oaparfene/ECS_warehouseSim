#include "rendercomponent.h"

RenderComponent::RenderComponent(QString _type, float _x, float _y, float _r, QColor _color) : QComponent()
{
    type = _type;
    x = _x;
    y = _y;
    r = _r;
    color = _color;
}
