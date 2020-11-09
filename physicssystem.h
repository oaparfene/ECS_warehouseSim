#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include <QHash>
#include <QVector2D>
#include <QGlobalStatic>

struct Velocity{
    QVector2D dir;
    float speed;
};

class PhysicsSystem
{
public:
    PhysicsSystem();
    static void simulate();
    static QHash<uint, QVector2D> position;
    static QHash<uint, QPolygonF*> geometry2D;
    static QHash<uint, Velocity> velocity;

private:

};

//Q_GLOBAL_STATIC(PhysicsSystem, PHYSICS_SYSTEM)

#endif // PHYSICSSYSTEM_H
