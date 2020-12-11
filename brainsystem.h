#ifndef BRAINSYSTEM_H
#define BRAINSYSTEM_H

#include "warehousefloor.h"
#include <QHash>

class BrainSystem
{
public:
    BrainSystem();
    static void simulate();
    static QHash<uint, bool> cargo; //  is this cargo being targeted by a mule? bool
    static QHash<uint, QVector<uint>> mule; // cargo target queue
    static QHash<uint, QVector<uint>> inventory; // collected cargo
    static QHash<uint, bool> depositDocks; // deposit dock
};

#endif // BRAINSYSTEM_H
