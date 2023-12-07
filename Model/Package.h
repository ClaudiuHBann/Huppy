#pragma once

#include <quuid.h>

#include "IModel.h"

namespace Model
{
class Package : public QObject, public IModel<int, QUuid, QString>
{
    Q_OBJECT;
    DEFINE_MODEL(Package, id, uuid, apps);
};
} // namespace Model
