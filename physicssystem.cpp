#include "physicssystem.h"

QHash<uint, QVector2D> PhysicsSystem::position = QHash<uint, QVector2D>();
QHash<uint, QPolygon*> PhysicsSystem::geometry2D = QHash<uint, QPolygon*>();

PhysicsSystem::PhysicsSystem()
{

}
