#include "pch.h"
#include "ListViewApp.h"

// TODO: make some magic macros?

namespace View
{
ListViewApp::ListViewApp(QObject *aParent /* = {} */) : QAbstractListModel(aParent)
{
}

int ListViewApp::rowCount(const QModelIndex & /* = {} */) const
{
    return mApps.count();
}

QVariant ListViewApp::data(const QModelIndex &index, int role /* = Qt::UserRole */) const
{
    if (index.row() >= rowCount())
    {
        return {};
    }

    switch (role)
    {
    case RoleID:
        return mApps.at(index.row()).Getid();

    case RoleCategory:
        return mApps.at(index.row()).Getcategory();

    case RoleName:
        return mApps.at(index.row()).Getname();

    case RoleProposed:
        return mApps.at(index.row()).Getproposed();

    default:
        return {};
    }
}

QHash<int, QByteArray> ListViewApp::roleNames() const
{
    return {{RoleID, "id"}, {RoleCategory, "category"}, {RoleName, "name"}, {RoleProposed, "proposed"}};
}

QVariantMap ListViewApp::get(int row) const
{
    const auto app = mApps.value(row);
    return {
        {"id", app.Getid()}, {"category", app.Getcategory()}, {"name", app.Getname()}, {"proposed", app.Getproposed()}};
}

void ListViewApp::append(const Model::App &aApp)
{
    beginInsertRows({}, mApps.count(), mApps.count());
    mApps.append(aApp);
    endInsertRows();
}

void ListViewApp::set(int row, const Model::App &aApp)
{
    if (row < 0 || row >= mApps.count())
    {
        return;
    }

    mApps.replace(row, aApp);
    // TODO: update only the roles that changed
    dataChanged(index(row, 0), index(row, 0), {RoleID, RoleCategory, RoleName, RoleProposed});
}

void ListViewApp::remove(int row)
{
    if (row < 0 || row >= mApps.count())
    {
        return;
    }

    beginRemoveRows({}, row, row);
    mApps.removeAt(row);
    endRemoveRows();
}
} // namespace View
