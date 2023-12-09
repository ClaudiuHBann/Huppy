#include "pch.h"
#include "ListViewCategory.h"

namespace View
{
ListViewCategory::ListViewCategory(QObject *aParent /* = {} */) : QAbstractListModel(aParent)
{
    mCategoryToApps.append({{69, "69", "420", 420}, {{69, 420, "proposed", false}, {69, 420, "proposed", false}}});
    mCategoryToApps.append({{69, "69", "420", 420}, {{69, 420, "proposed", false}, {69, 420, "proposed", false}}});
    mCategoryToApps.append({{69, "69", "420", 420}, {{69, 420, "proposed", false}, {69, 420, "proposed", false}}});
}

int ListViewCategory::rowCount(const QModelIndex & /* = {} */) const
{
    return mCategoryToApps.count();
}

QPair<QVariant, QVariantList> ListViewCategory::GetCTAS(int row) const
{
    QVariantList apps{};
    for (const auto &app : mCategoryToApps[row].second)
    {
        apps.append(QVariant::fromValue(app));
    }

    return {QVariant::fromValue(mCategoryToApps[row].first), apps};
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
        return QVariant::fromValue(mCategoryToApps[index.row()].first);

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

void ListViewCategory::append(const CategoryToApp & /*aCategoryToApp*/)
{
    beginInsertRows({}, mCategoryToApps.count(), mCategoryToApps.count());

    // TODO: implement me
    // const auto it = std::ranges::find_if(mCategoryToApps,
    //[&](const auto &aPair) { return aPair.first == aCategoryToApp.category; });
    // it->second.append(aCategoryToApp.app);

    endInsertRows();
}

void ListViewCategory::set(int row, const CategoryToApp & /*aCategoryToApp*/)
{
    if (row < 0 || row >= mCategoryToApps.count())
    {
        return;
    }

    // TODO: implement me
    // const auto it = std::ranges::find_if(mCategoryToApps,
    //[&](const auto &aPair) { return aPair.first == aCategoryToApp.category; });
    // it->second.replace(row, aCategoryToApp.app);
    //  TODO: update only the roles that changed
    dataChanged(index(row, 0), index(row, 0), {RoleCategory, RoleApps});
}

void ListViewCategory::remove(int row)
{
    if (row < 0 || row >= mCategoryToApps.count())
    {
        return;
    }

    beginRemoveRows({}, row, row);
    // TODO: this is bad
    mCategoryToApps.removeAt(row);
    endRemoveRows();
}
} // namespace View
