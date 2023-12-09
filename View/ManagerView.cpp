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
    const auto apps = mClientSQL.SelectAll<App>();
    for (const auto &category : mClientSQL.SelectAll<Category>())
    {
        for (const auto &app : apps)
        {
            if (category.Getid() != app.Getcategory())
            {
                continue;
            }

            mCategoryToApps[category.Getname()] += app;
        }
    }
}

void ManagerView::Initialize()
{
    const auto root = mEngine.rootObjects().first();
    const auto viewApp = root->findChild<QObject *>("viewApp", Qt::FindDirectChildrenOnly);
    mListViewApp = viewApp->findChild<decltype(mListViewApp)>("listViewApp", Qt::FindDirectChildrenOnly);

    InitializeApps();
}
} // namespace View
