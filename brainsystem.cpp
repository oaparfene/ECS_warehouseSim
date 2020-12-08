#include "brainsystem.h"
#include "physicssystem.h"
#include "rendersystem.h"

#define COLLISIONDIST 50

QHash<uint, bool> BrainSystem::cargo = QHash<uint, bool>();
QHash<uint, QVector<uint>> BrainSystem::mule = QHash<uint, QVector<uint>>();
QHash<uint, QVector<uint>> BrainSystem::inventory = QHash<uint, QVector<uint>>();

BrainSystem::BrainSystem()
{

}

void BrainSystem::simulate()
{
    if (mule.isEmpty()) // no mules means there is nothing to simulate
        return;
    if (cargo.isEmpty()) // no cargos means no new movement for mules
    {
        QHashIterator<uint, QVector<uint>> i(BrainSystem::mule);
        while (i.hasNext())
        {
            i.next();
            PhysicsSystem::velocity.find(i.key())->dir = QVector2D(0, 0);
            // to do : point to deposit bay if !inventory.isEmpty()
        }
    }
    else // normal operations
    {
        QHashIterator<uint, QVector<uint>> i(BrainSystem::mule); // for each mule
        while (i.hasNext())
        {
            i.next();
            if (!i.value().isEmpty()) // if mule already has task
            {
                uint tempID = i.value().first();
                QVector2D distance_from_cargo = (*PhysicsSystem::position.find(i.value().first())) - (*PhysicsSystem::position.find(i.key()));
                if (distance_from_cargo.length() < COLLISIONDIST) //found cargo
                {
                    RenderSystem::appearance.find(i.value().first())->color = QColor(0xBF616A);

                    mule.find(i.key())->pop_front();
                    Entity::deleteEntByID(tempID);
                }

                continue;
            }
            qDebug() << *PhysicsSystem::position.find(i.key());

            QHashIterator<uint, bool> j(BrainSystem::cargo);
            if (!j.findNext(true)) // first cargo that exists and is valid
                return;
            mule.find(i.key())->append(j.key()); // add cargo ID to mule brain (decision to go get said cargo)
            *cargo.find(j.key()) = false; // cargo will be ignored by other mules
            PhysicsSystem::velocity.find(i.key())->dir = (*PhysicsSystem::position.find(j.key()) - *PhysicsSystem::position.find(i.key())).normalized();

        }
    }

}
