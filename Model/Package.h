#pragma once

#include <quuid.h>

#include "IModel.h"

namespace Model
{
class Package : public IModel<int, QUuid, QString>
{
    Q_GADGET;
    DEFINE_MODEL(Package, id, uuid, apps);
};
} // namespace Model
