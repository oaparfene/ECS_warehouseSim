#include "rendersystem.h"
#include "physicssystem.h"
#include "rendercomponent.h"

QHash<uint, Appearance> RenderSystem::appearance = QHash<uint, Appearance>();
QPainter* RenderSystem::p = nullptr;

RenderSystem::RenderSystem()
{

}

void RenderSystem::simulate()
{

    for (int i=0; i<=GW; i++)
    {
        p->drawLine((i*CW),0,(i*CW),CH*GH);
    }
    for (int i=0; i<=GH; i++)
    {
        p->drawLine(0,(i*CH),CW*GW,(i*CH));
    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);

    if (!appearance.isEmpty())
    {
        QHashIterator<uint, Appearance> i(RenderSystem::appearance);
        while (i.hasNext())
        {
            i.next();
            brush.setColor(i.value().color);
            p->setBrush(brush);
            p->drawPolygon(*i.value().polygon);
        }
    }

}
