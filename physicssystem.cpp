#include "physicssystem.h"
#include "rendersystem.h"

QHash<uint, QVector2D> PhysicsSystem::position = QHash<uint, QVector2D>();
QHash<uint, QPolygonF> PhysicsSystem::geometry2D = QHash<uint, QPolygonF>();
QHash<uint, Velocity> PhysicsSystem::velocity = QHash<uint,Velocity>();
QHash<uint, bool> PhysicsSystem::collisionMask = QHash<uint, bool>();

PhysicsSystem::PhysicsSystem()
{

}

void PhysicsSystem::simulate()
{
    if (!velocity.isEmpty())
    {
        QHashIterator<uint, Velocity> i(PhysicsSystem::velocity);
        while (i.hasNext()) // for all entities with a velocity component
        {
            i.next();
            QVector2D translation = i.value().dir * i.value().speed; // move them part 1

            *position.find(i.key()) += translation; // move them part 2
            RenderSystem::appearance.find(i.key())->polygon->translate(translation.x(), translation.y()); // move rendercomponent
        }
    }
}
