#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include <QHash>
#include <QVector2D>

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
    static QHash<uint, QPolygonF> geometry2D; // make not pointer: done
    static QHash<uint, Velocity> velocity;
    static QHash<uint, bool> collisionMask; // cuurently only one layer therefore bool

private:

};

#endif // PHYSICSSYSTEM_H
