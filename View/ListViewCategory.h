#pragma once

#include <qabstractitemmodel.h>

#include "Model/App.h"
#include "Model/Category.h"

namespace View
{
class ListViewCategory : public QAbstractListModel
{
    Q_OBJECT;

  public:
    enum CategoryRole
    {
        RoleCategory = Qt::UserRole,
        RoleApps,
    };
    Q_ENUM(CategoryRole)

    ListViewCategory(QObject *aParent = {});

    int rowCount(const QModelIndex & = {}) const;
    QVariant data(const QModelIndex &index, int role = Qt::UserRole) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE QVariantMap get(int row) const;
    Q_INVOKABLE void append(const Model::Category &aCategory, const Model::App &aApp);
    Q_INVOKABLE void set(int row, const Model::Category &aCategory, const Model::App &aApp);
    Q_INVOKABLE void remove(int row, const Model::Category &aCategory, const Model::App &aApp);

  private:
    QMap<Model::Category, QList<Model::App>> mCategoryToApps;

    QPair<QVariant, QVariantList> GetCTAS(int row) const;
};
} // namespace View
