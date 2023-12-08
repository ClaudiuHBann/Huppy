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
    Utility::Database mDatabase;
};
} // namespace Client
