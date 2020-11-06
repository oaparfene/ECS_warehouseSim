#include "warehousefloor.h"
#include "rendersystem.h"
#include "rendercomponent.h"

WarehouseFloor::WarehouseFloor(QWidget *parent) :
    QWidget(parent),
    gridHeight(GH),
    gridWidth(GW),
    cellHeight(CH),
    cellWidth(CW)
{
    //renderSystem = new RenderSystem();

    timer = new QTimer(nullptr);
    timer->setInterval(30);
    connect(timer, SIGNAL(timeout()), this, SLOT(simulate()));
    instance_environment();
}

void WarehouseFloor::instance_environment()
{
    //dep = new DepositDock(this, "Deposit Bay", 0, 0);
    //itemList.append(dep);
    //MuleRobot* mule = new MuleRobot(this, "mule1", 100,100, 5, 25, 10);
    //itemList.append(mule);
    RENDER_SYSTEM->p = new QPainter (this);

    update();
}

void WarehouseFloor::paintEvent(QPaintEvent *)
{
    RENDER_SYSTEM->p->begin(this);
    RENDER_SYSTEM->simulate();
    RENDER_SYSTEM->p->end();
}

void WarehouseFloor::startSim()
{
    timer->start();
}

void WarehouseFloor::simulate()
{

    RENDER_SYSTEM->simulate();
//    QList<RenderItem*>::iterator it;
//    for (it = itemList.begin() ; it != itemList.end() ; it++)
//    {
//        if((*it)->simulate())
//            break;
//    }
    update();
}

void WarehouseFloor::newOrder()
{
    int orderSize = QRandomGenerator::global()->bounded(1,10);
    for (int i = 0 ; i < orderSize ; i++)
    {
        float tempx = QRandomGenerator::global()->bounded(2,GW);
        float tempy = QRandomGenerator::global()->bounded(0,GH*0.8);
        if (tempy >= GH*0.4)
            tempy += GH*0.2;
        tempx = int(tempx);
        tempy = int(tempy);

        Entity ent;
        ent.addComponent(new PositionComponent(&ent, QVector2D((tempx+0.5)*CW, (tempy+0.5)*CH)));
        QPolygon* poly = new QPolygon(QRect(0,0,CW,CH));
        ent.addComponent(new Geometry2DComponent(&ent, poly)); //center?

        QPointF renderPoints[4] = {
            QPointF(tempx*CW,tempy*CH),
            QPointF((tempx+1)*CW,tempy*CH),
            QPointF((tempx+1)*CW,(tempy+1)*CH),
            QPointF(tempx*CW,(tempy+1)*CH)
        };

        ent.addComponent(new RenderComponent(&ent, renderPoints));
        qDebug() << "phys: " << PHYSICS_SYSTEM->position.size();


//        Qt3DCore::QEntity* entity = new Qt3DCore::QEntity();
//        RenderComponent* component = new RenderComponent("square", (tempx+0.5)*CW, (tempy+0.5)*CH, 25, QColor(0x5E81AC));
//        entity->addComponent(component);
//        RENDER_SYSTEM->comps.append(component);
//        entityList.append(entity);
    }
    update();
}

//CargoItem* WarehouseFloor::getOrder()
//{
//    if (cargoList.isEmpty())
//        return nullptr;
//    return cargoList.takeFirst();
//}

//DepositDock* WarehouseFloor::getDep() const
//{
//    return dep;
//}

//QVector2D WarehouseFloor::getDepPos() const
//{
//    return dep->getPos();
//}

//void WarehouseFloor::removeCargo(CargoItem * cargo)
//{
//    itemList.removeOne(cargo);
//}
