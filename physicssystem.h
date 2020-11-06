#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include <QMultiHash>
#include <QVector2D>
#include <QGlobalStatic>

class PhysicsSystem
{
public:
    PhysicsSystem();
    QMultiHash<uint, QVector2D> position;
    QMultiHash<uint, QPolygon*> geometry2D;

private:

};

Q_GLOBAL_STATIC(PhysicsSystem, PHYSICS_SYSTEM)

#endif // PHYSICSSYSTEM_H
