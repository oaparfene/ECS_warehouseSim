#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include <QHash>
#include <QVector2D>
#include <QGlobalStatic>

class PhysicsSystem
{
public:
    PhysicsSystem();
    static QHash<uint, QVector2D> position;
    static QHash<uint, QPolygon*> geometry2D;

private:

};

//Q_GLOBAL_STATIC(PhysicsSystem, PHYSICS_SYSTEM)

#endif // PHYSICSSYSTEM_H
