#include "pch.h"
#include "ManagerView.h"

#include "Model/Category.h"

using namespace Model;

namespace View
{
ManagerView::ManagerView(QQmlApplicationEngine &aEngine, Client::ClientSQL &aClientSQL, QObject *aParent)
    : QObject(aParent), mEngine(aEngine), mClientSQL(aClientSQL)
{
}

void ManagerView::InitializeApps()
{
    auto apps = mClientSQL.SelectAll<App>();
    for (const auto &category : mClientSQL.SelectAll<Category>())
    {
        for (auto &app : apps)
        {
            if (category.Getid() != app.Getcategory())
            {
                continue;
            }

            mCategoryToApps[category.Getname()] += std::move(app);
        }
    }
}

void ManagerView::Initialize()
{
    const auto root = mEngine.rootObjects().first();
    const auto viewCategory = root->findChild<QObject *>("viewCategory", Qt::FindDirectChildrenOnly);
    mListViewCategory =
        viewCategory->findChild<decltype(mListViewCategory)>("listViewCategory", Qt::FindDirectChildrenOnly);
    // const auto delegateCategory = viewCategory->findChild<QObject *>("delegateCategory");
    // mListViewCategory =
    // delegateCategory->findChild<decltype(mListViewCategory)>("listViewCategory", Qt::FindDirectChildrenOnly);

    InitializeApps();
}
} // namespace View
