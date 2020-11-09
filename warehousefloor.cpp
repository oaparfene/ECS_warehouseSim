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
    timer = new QTimer(nullptr);
    timer->setInterval(30);
    connect(timer, SIGNAL(timeout()), this, SLOT(simulate()));
    instance_environment();
}

void WarehouseFloor::instance_environment()
{

    Entity* ent = new Entity();
    ent->addComponent(new PositionComponent(ent, QVector2D(100, 100)));

    QVector<QPointF> geometryPoints;
    for (float i=0; i<=1 ; i=i+0.0625)
    {
        geometryPoints.append(QPointF(37*cos(i*2*M_PI), 37*sin(i*2*M_PI)));
    }
    QPolygonF* poly = new QPolygonF(geometryPoints);
    ent->addComponent(new Geometry2DComponent(ent, poly));
    geometryPoints.clear();

    for (float i=0; i<=1 ; i=i+0.0625)
    {
        geometryPoints.append(QPointF(100, 100) + QPointF(37*cos(i*2*M_PI), 37*sin(i*2*M_PI)));
    }
    poly = new QPolygonF(geometryPoints);
    Appearance app;
    app.polygon = poly;
    app.color = QColor(0xEBCB8B);
    ent->addComponent(new RenderComponent(ent, app));

    Velocity vel;
    vel.dir = QVector2D(1,0);
    vel.speed  = 10;
    ent->addComponent(new VelocityComponent(ent, vel));

    //dep = new DepositDock(this, "Deposit Bay", 0, 0);
    //itemList.append(dep);
    //MuleRobot* mule = new MuleRobot(this, "mule1", 100,100, 5, 25, 10);
    //itemList.append(mule);
    RenderSystem::p = new QPainter (this);

    update();
}

void WarehouseFloor::paintEvent(QPaintEvent *)
{
    RenderSystem::p->begin(this);
    RenderSystem::simulate();
    RenderSystem::p->end();
}

void WarehouseFloor::startSim()
{
    timer->start();
}

void WarehouseFloor::simulate()
{

    RenderSystem::simulate();
    PhysicsSystem::simulate();
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

        Entity* ent = new Entity();
        ent->addComponent(new PositionComponent(ent, QVector2D((tempx+0.5)*CW, (tempy+0.5)*CH)));
        QPolygonF* poly = new QPolygonF(QRectF(0,0,CW,CH));
        ent->addComponent(new Geometry2DComponent(ent, poly)); //center?

        QVector<QPointF> renderPoints;
        renderPoints.append(QPointF(tempx*CW,tempy*CH));
        renderPoints.append(QPointF((tempx+1)*CW,tempy*CH));
        renderPoints.append(QPointF((tempx+1)*CW,(tempy+1)*CH));
        renderPoints.append(QPointF(tempx*CW,(tempy+1)*CH));
        poly = new QPolygonF(renderPoints);
        Appearance app;
        app.polygon = poly;
        app.color = QColor(0x5E81AC);
        ent->addComponent(new RenderComponent(ent, app));
        //qDebug() << "phys: " << PhysicsSystem::position.size();


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
