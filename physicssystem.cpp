#include "physicssystem.h"
#include "rendersystem.h"

QHash<uint, QVector2D> PhysicsSystem::position = QHash<uint, QVector2D>();
QHash<uint, QPolygonF*> PhysicsSystem::geometry2D = QHash<uint, QPolygonF*>();
QHash<uint, Velocity> PhysicsSystem::velocity = QHash<uint,Velocity>();

PhysicsSystem::PhysicsSystem()
{

}

void PhysicsSystem::simulate()
{
    if (!velocity.isEmpty())
    {
        QHashIterator<uint, Velocity> i(PhysicsSystem::velocity);
        while (i.hasNext())
        {
            i.next();
            QVector2D translation = i.value().dir * i.value().speed;
            *position.find(i.key()) += translation;
            RenderSystem::appearance.find(i.key())->polygon->translate(translation.x(), translation.y());
        }
    }
}
