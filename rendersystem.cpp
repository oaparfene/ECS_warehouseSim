#include "rendersystem.h"
#include "physicssystem.h"
#include "rendercomponent.h"

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
//    QList<RenderComponent*>::iterator it;
//    for (it = comps.begin(); it != comps.end(); it++)
//    {
//        if ((*it)->type == "square")
//        {
//            float a,b,c;
//            a = (*it)->x;
//            b = (*it)->y;
//            c = (*it)->r;
//            QBrush brush;
//            brush.setColor((*it)->color);
//            brush.setStyle(Qt::SolidPattern);
//            p->setBrush(brush);
//            p->drawRect(a-c, b-c, 2*c, 2*c);
//        }
//    }

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    p->setBrush(brush);
    //brush.setColor((*it)->color);

    qDebug() << RENDER_SYSTEM->points.isEmpty();
    qDebug() <<  points.size();

    if (!points.isEmpty())
    {
        QMultiHash<uint, QPointF*>::iterator i = points.find(1);
        while (i != points.end())
        {
            p->drawPolygon(i.value(),4);
        }
    }

}
