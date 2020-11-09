#ifndef WAREHOUSEFLOOR_H
#define WAREHOUSEFLOOR_H

#include <QtMath>
#include <QWidget>
#include <QTimer>
#include <QPainter>
#include <QRandomGenerator>
#include <QDebug>
#include <QEntity>
#include <QComponent>
//#include "cargoitem.h"
//#include "mulerobot.h"
//#include "depositdock.h"

#include "entity.h"
#include "component.h"
#include "positioncomponent.h"
#include "geometry2dcomponent.h"
#include "velocitycomponent.h"
#include "physicssystem.h"

#define GH 10
#define GW 20
#define CH 50
#define CW 50

class RenderSystem;
class RenderComponent;

class WarehouseFloor : public QWidget
{
    Q_OBJECT
public:
    WarehouseFloor(QWidget *parent = 0);
    virtual ~WarehouseFloor() {};
    virtual void paintEvent(QPaintEvent *event);
    void startSim();
    void newOrder();

    //CargoItem* getOrder();
    //DepositDock* getDep() const;
    //QVector2D getDepPos() const;
    //void removeCargo(CargoItem*);

    const int gridHeight;
    const int gridWidth;
    const int cellHeight;
    const int cellWidth;

private slots:
    void simulate();

private:
    RenderSystem* renderSystem;
    QList<Qt3DCore::QEntity*> entityList;
    //DepositDock* dep;
    //QList<RenderItem*> itemList;
    //QList<CargoItem*> cargoList;
    void instance_environment();
    QTimer* timer;
};

#endif // WAREHOUSEFLOOR_H
