#include "pch.h"
#include "ListViewCategory.h"

using namespace Model;

namespace View
{
ListViewCategory::ListViewCategory(QObject *aParent /* = {} */) : QAbstractListModel(aParent)
{
}

int ListViewCategory::rowCount(const QModelIndex & /* = {} */) const
{
    return mCategoryToApps.count();
}

QPair<QVariant, QVariantList> ListViewCategory::GetCTAS(int row) const
{
    QVariantList apps{};
    for (const auto &app : mCategoryToApps[mCategoryToApps.keys()[row]])
    {
        apps.append(QVariant::fromValue(app));
    }

    return {QVariant::fromValue(mCategoryToApps.keys()[row]), apps};
}

QVariant ListViewCategory::data(const QModelIndex &index, int role /* = Qt::UserRole */) const
{
    if (index.row() >= rowCount())
    {
        return {};
    }

    switch (role)
    {
    case RoleCategory:
        return QVariant::fromValue(mCategoryToApps.keys()[index.row()]);

    case RoleApps:
        return GetCTAS(index.row()).second;

    default:
        return {};
    }
}

QHash<int, QByteArray> ListViewCategory::roleNames() const
{
    return {{RoleCategory, "category"}, {RoleApps, "apps"}};
}

QVariantMap ListViewCategory::get(int row) const
{
    auto ctas(GetCTAS(row));
    return {{"category", ctas.first}, {"apps", ctas.second}};
}

void ListViewCategory::append(const Category &aCategory, const App &aApp)
{
    beginInsertRows({}, mCategoryToApps.count(), mCategoryToApps.count());
    mCategoryToApps[aCategory] += aApp;
    endInsertRows();
}

void ListViewCategory::set(int row, const Model::Category &aCategory, const Model::App &aApp)
{
    if (row < 0 || row >= mCategoryToApps.count())
    {
        return;
    }

    // TODO: is this right?
    const auto it = std::ranges::find_if(mCategoryToApps[aCategory],
                                         [&](const auto &aAppIn) { return aAppIn.Getid() == aApp.Getid(); });
    *it = aApp;
    // TODO: update only the roles that changed
    dataChanged(index(row, 0), index(row, 0), {RoleCategory, RoleApps});
}

void ListViewCategory::remove(int row, const Model::Category &aCategory, const Model::App &aApp)
{
    if (row < 0 || row >= mCategoryToApps.count())
    {
        return;
    }

    beginRemoveRows({}, row, row);
    mCategoryToApps[aCategory].removeOne(aApp);
    endRemoveRows();
}
} // namespace View
