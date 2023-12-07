#pragma once

#include "Utility/Database.h"

namespace Client
{
class ClientSQL : public QObject
{
    Q_OBJECT;

  public:
    ClientSQL(QObject *aParent);

  private:
    Database mDatabase;
};
} // namespace Client
