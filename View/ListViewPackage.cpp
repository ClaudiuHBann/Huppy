#include "pch.h"
#include "ListViewPackage.h"

// TODO: make some magic macros?

namespace View
{
ListViewPackage::ListViewPackage(QObject *aParent /* = {} */) : QAbstractListModel(aParent)
{
}

int ListViewPackage::rowCount(const QModelIndex & /* = {} */) const
{
    return mPackage.count();
}

QVariant ListViewPackage::data(const QModelIndex &index, int role /* = Qt::UserRole */) const
{
    if (index.row() >= rowCount())
    {
        return {};
    }

    switch (role)
    {
    case RoleID:
        return mPackage.at(index.row()).Getid();

    case RoleCategory:
        return mPackage.at(index.row()).Getcategory();

    case RoleName:
        return mPackage.at(index.row()).Getname();

    case RoleProposed:
        return mPackage.at(index.row()).Getproposed();

    case RoleImage:
        return mPackage.at(index.row()).Getimage();

    default:
        return {};
    }
}

QHash<int, QByteArray> ListViewPackage::roleNames() const
{
    return {{RoleID, "id"},
            {RoleCategory, "category"},
            {RoleName, "name"},
            {RoleProposed, "proposed"},
            {RoleImage, "image"}};
}

QVariantMap ListViewPackage::get(int row) const
{
    const auto app = mPackage.value(row);
    return {{"id", app.Getid()},
            {"category", app.Getcategory()},
            {"name", app.Getname()},
            {"proposed", app.Getproposed()},
            {"image", app.Getimage()}};
}

void ListViewPackage::append(const Model::App &aApp)
{
    beginInsertRows({}, rowCount(), rowCount());
    mPackage.append(aApp);
    endInsertRows();
}

void ListViewPackage::set(int row, const Model::App &aApp)
{
    if (row < 0 || row >= rowCount())
    {
        return;
    }

    mPackage.replace(row, aApp);
    // TODO: update only the roles that changed
    dataChanged(index(row, 0), index(row, 0), {RoleID, RoleCategory, RoleName, RoleProposed});
}

void ListViewPackage::remove(const Model::App &aApp)
{
    const int row = mPackage.indexOf(aApp);
    if (row < 0 || row >= rowCount())
    {
        return;
    }

    beginRemoveRows({}, row, row);
    mPackage.removeAt(row);
    endRemoveRows();
}
} // namespace View
