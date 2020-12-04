#ifndef BRAINSYSTEM_H
#define BRAINSYSTEM_H

#include "warehousefloor.h"
#include <QHash>

class BrainSystem
{
public:
    BrainSystem();
    static void simulate();
    static QHash<uint, bool> cargo;
    static QHash<uint, QVector<uint>> mule;
    static QHash<uint, QVector<uint>> inventory;
};

#endif // BRAINSYSTEM_H
