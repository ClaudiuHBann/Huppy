#include "pch.h"
#include "ClientSQL.h"

namespace
{
constexpr auto DB_DRIVER = "QPSQL";

constexpr auto DB_HOST_NAME = "localhost";
constexpr auto DB_HOST_PORT = 5432;

constexpr auto DB_USER_NAME = "Huppy";
constexpr auto DB_PASSWORD = "happyhubapp";

constexpr auto DB_DATABASE_NAME = "Huppy";
} // namespace

namespace Client
{
ClientSQL::ClientSQL(QObject *aParent) : QObject(aParent), mDatabase(QSqlDatabase::addDatabase(DB_DRIVER))
{
    Initialize();
}

void ClientSQL::Initialize()
{
    if (!mDatabase.isValid())
    {
        qDebug() << QString("%1 -> %2").arg(Q_FUNC_INFO, mDatabase.lastError().text());
        return;
    }

    mDatabase.setHostName(DB_HOST_NAME);
    mDatabase.setPort(DB_HOST_PORT);

    mDatabase.setUserName(DB_USER_NAME);
    mDatabase.setPassword(DB_PASSWORD);

    mDatabase.setDatabaseName(DB_DATABASE_NAME);

    mInitialized = mDatabase.open();
    if (!mDatabase.isOpen())
    {
        qDebug() << QString("%1 -> %2").arg(Q_FUNC_INFO, mDatabase.lastError().text());
        return;
    }
}
} // namespace Client
