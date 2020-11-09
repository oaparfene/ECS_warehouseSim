#include "rendersystem.h"
#include "physicssystem.h"
#include "rendercomponent.h"

QHash<uint, QPolygon*> RenderSystem::points = QHash<uint, QPolygon*>();
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
    p->setBrush(brush);
    //brush.setColor((*it)->color);

    qDebug() << RenderSystem::points.isEmpty();
    qDebug() <<  RenderSystem::points.size();

    //QPolygon* t;

    if (!points.isEmpty())
    {
        QHashIterator<uint, QPolygon*> i(RenderSystem::points); //= RenderSystem::points.find(1);
        while (i.hasNext())
        {
            i.next();
            qDebug() << "i:" << *(i.value());
            p->drawPolygon(*i.value());
        }
    }

}
