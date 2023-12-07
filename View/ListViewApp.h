#pragma once

#include <qabstractitemmodel.h>

#include "Model/App.h"

namespace View
{
class ListViewApp : public QAbstractListModel
{
    Q_OBJECT;

  public:
    enum AppRole
    {
        RoleID = Qt::UserRole,
        RoleCategory,
        RoleName,
        RoleProposed
    };
    Q_ENUM(AppRole)

    ListViewApp(QObject *aParent = {}) : QAbstractListModel(aParent)
    {
        append({69, 420, "name", false});
        append({69, 420, "name", false});
        append({69, 420, "name", false});
        append({69, 420, "name", false});
        append({69, 420, "name", false});
    }

    int rowCount(const QModelIndex & = QModelIndex()) const
    {
        return mApps.count();
    }

    QVariant data(const QModelIndex &index, int role = Qt::UserRole) const
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

    QHash<int, QByteArray> roleNames() const
    {
        return {{RoleID, "id"}, {RoleCategory, "category"}, {RoleName, "name"}, {RoleProposed, "proposed"}};
    }

    Q_INVOKABLE QVariantMap get(int row) const
    {
        const auto app = mApps.value(row);
        return {{"id", app.Getid()},
                {"category", app.Getcategory()},
                {"name", app.Getname()},
                {"proposed", app.Getproposed()}};
    }

    Q_INVOKABLE void append(const Model::App &aApp)
    {
        beginInsertRows({}, mApps.count(), mApps.count());
        mApps.append(aApp);
        endInsertRows();
    }

    Q_INVOKABLE void set(int row, const Model::App &aApp)
    {
        if (row < 0 || row >= mApps.count())
        {
            return;
        }

        mApps.replace(row, aApp);
        dataChanged(index(row, 0), index(row, 0), {RoleID, RoleCategory, RoleName, RoleProposed});
    }

    Q_INVOKABLE void remove(int row)
    {
        if (row < 0 || row >= mApps.count())
        {
            return;
        }

        beginRemoveRows({}, row, row);
        mApps.removeAt(row);
        endRemoveRows();
    }

  private:
    QList<Model::App> mApps;
};
} // namespace View
