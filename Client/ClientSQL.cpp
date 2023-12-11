#include "pch.h"
#include "ClientSQL.h"

namespace
{
const auto DB_DRIVER = QString::fromStdString(static_cast<char *>(AY_OBFUSCATE("QPSQL")));

const auto DB_HOST_NAME = QString::fromStdString(static_cast<char *>(AY_OBFUSCATE("162.55.32.18")));
constexpr auto DB_HOST_PORT = 5432;

const auto DB_USER_NAME = QString::fromStdString(static_cast<char *>(AY_OBFUSCATE("huppy")));
const auto DB_PASSWORD = QString::fromStdString(static_cast<char *>(AY_OBFUSCATE("huppyhubapp")));

const auto DB_DATABASE_NAME = QString::fromStdString(static_cast<char *>(AY_OBFUSCATE("Huppy")));
} // namespace

namespace Client
{
ClientSQL::ClientSQL(QObject *aParent) : QObject(aParent), mDatabase(QSqlDatabase::addDatabase(DB_DRIVER))
{
    Initialize();
}

void ClientSQL::Initialize()
{
    Q_ASSERT_X(mDatabase.isValid(), "function", mDatabase.lastError().text().toLatin1().constData());

    mDatabase.setHostName(DB_HOST_NAME);
    mDatabase.setPort(DB_HOST_PORT);

    mDatabase.setDatabaseName(DB_DATABASE_NAME);

    Q_ASSERT_X(mDatabase.open(DB_USER_NAME, DB_PASSWORD), "function",
               mDatabase.lastError().text().toLatin1().constData());
}
} // namespace Client
