#include "pch.h"
#include "ClientSQL.h"

namespace Client
{
ClientSQL::ClientSQL(QObject *aParent) : QObject(aParent), mDatabase(this)
{
}
} // namespace Client
