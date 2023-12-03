#pragma once

#include <QtSql/qsqldatabase.h>
#include <qobject.h>

namespace Client
{
class ClientSQL : public QObject
{
    Q_OBJECT;

  public:
    ClientSQL(QObject *aParent);

  private:
    QSqlDatabase mDatabase;

    bool mInitialized{};

    void Initialize();
};
} // namespace Client
