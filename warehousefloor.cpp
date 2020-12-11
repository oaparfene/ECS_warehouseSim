#include "warehousefloor.h"
#include "rendersystem.h"
#include "physicssystem.h"
#include "brainsystem.h"
#include "rendercomponent.h"
#include "positioncomponent.h"
#include "geometry2dcomponent.h"
#include "velocitycomponent.h"
#include "collisioncomponent.h"
#include "cargocomponent.h"
#include "mulecomponent.h"
#include "inventorycomponent.h"
#include "depositdockflagcomponent.h"

#define MULE_RADIUS 25
#define MULE_RESOLUTION 0.0625

#define MULE_SPAWN_COORDX 100
#define MULE_SPAWN_COORDY 100

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
    QPolygonF* poly = new QPolygonF(geometryPoints);
    geometryPoints.clear();

    for (float i=0; i<=1 ; i=i+MULE_RESOLUTION)
    {
        geometryPoints.append(QPointF(MULE_SPAWN_COORDX, MULE_SPAWN_COORDY) + QPointF(MULE_RADIUS*cos(i*2*M_PI), MULE_RADIUS*sin(i*2*M_PI)));
    }
    poly = new QPolygonF(geometryPoints);
    ent->addComponent(new Geometry2DComponent(ent, poly));
    Appearance app;
    app.polygon = poly;
    app.color = QColor(0xEBCB8B);
    ent->addComponent(new RenderComponent(ent, app));

    Velocity vel;
    vel.dir = QVector2D(0,0);
    vel.speed  = 10;
    ent->addComponent(new VelocityComponent(ent, vel));

    ent->addComponent(new CollisionComponent(ent, true));

    ent->addComponent(new MuleComponent(ent));

    // Deposit Dock instantiation

    ent = new Entity();
    ent->addComponent(new PositionComponent(ent, QVector2D(0, 0)));
    QVector<QPointF> renderPoints;
    renderPoints.append(QPointF(0,0));
    renderPoints.append(QPointF(CW,0));
    renderPoints.append(QPointF(CW,CH));
    renderPoints.append(QPointF(0,CH));
    poly = new QPolygonF(renderPoints);
    ent->addComponent(new Geometry2DComponent(ent,poly));
    app.polygon = poly;
    app.color = QColor(0xB48EAD);
    ent->addComponent(new RenderComponent(ent, app));
    ent->addComponent(new CollisionComponent(ent, true));
    ent->addComponent(new DepositDockFlagComponent(ent));

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
    BrainSystem::simulate();
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
        //QPolygonF* poly = new QPolygonF(QRectF(0,0,CW,CH));

        QVector<QPointF> renderPoints;
        renderPoints.append(QPointF(tempx*CW,tempy*CH));
        renderPoints.append(QPointF((tempx+1)*CW,tempy*CH));
        renderPoints.append(QPointF((tempx+1)*CW,(tempy+1)*CH));
        renderPoints.append(QPointF(tempx*CW,(tempy+1)*CH));
        QPolygonF* poly = new QPolygonF(renderPoints);
        ent->addComponent(new Geometry2DComponent(ent,poly));
        Appearance app;
        app.polygon = poly;
        app.color = QColor(0x5E81AC);
        ent->addComponent(new RenderComponent(ent, app));
        ent->addComponent(new CollisionComponent(ent, true));
        ent->addComponent(new CargoComponent(ent));
    }
    update();
}
