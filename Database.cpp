#include "pch.h"
#include "Database.h"

namespace
{
constexpr auto DB_DRIVER = "QPSQL";

constexpr auto DB_HOST_NAME = "localhost";
constexpr auto DB_HOST_PORT = 5432;

constexpr auto DB_USER_NAME = "Huppy";
constexpr auto DB_PASSWORD = "happyhubapp";

constexpr auto DB_DATABASE_NAME = "Huppy";
} // namespace

Database::Database(QObject *aParent) : QObject(aParent), mDatabase(QSqlDatabase::addDatabase(DB_DRIVER))
{
    Initialize();
}
#include "Model/App.h"

void Database::Initialize()
{
    Q_ASSERT_X(mDatabase.isValid(), "function", mDatabase.lastError().text().toStdString().c_str());

    mDatabase.setHostName(DB_HOST_NAME);
    mDatabase.setPort(DB_HOST_PORT);

    mDatabase.setDatabaseName(DB_DATABASE_NAME);

    Q_ASSERT_X(mDatabase.open(DB_USER_NAME, DB_PASSWORD), "function",
               mDatabase.lastError().text().toStdString().c_str());
}
