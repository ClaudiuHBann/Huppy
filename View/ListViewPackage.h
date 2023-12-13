#pragma once

#include <qabstractitemmodel.h>

#include "Model/App.h"

namespace View
{
class ListViewPackage : public QAbstractListModel
{
    Q_OBJECT;

  public:
    enum AppRole
    {
        RoleID = Qt::UserRole,
        RoleCategory,
        RoleName,
        RoleProposed,
        RoleImage
    };
    Q_ENUM(AppRole)

    ListViewPackage(QObject *aParent = {});

    int rowCount(const QModelIndex & = {}) const;
    QVariant data(const QModelIndex &index, int role = Qt::UserRole) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE QVariantMap get(int row) const;
    Q_INVOKABLE void append(const Model::App &aApp);
    Q_INVOKABLE void set(int row, const Model::App &aApp);
    Q_INVOKABLE void remove(const Model::App &aApp);

  private:
    QList<Model::App> mPackage;
};
} // namespace View
