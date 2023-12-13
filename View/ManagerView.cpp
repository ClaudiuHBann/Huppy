#include "pch.h"
#include "ManagerView.h"

#include "Model/Category.h"

using namespace Model;

namespace View
{
void ManagerView::InitializeApps()
{
    auto apps = mClientSQL->SelectAll<App>();
    for (const auto &category : mClientSQL->SelectAll<Category>())
    {
        for (auto &app : apps)
        {
            if (category.Getid() != app.Getcategory())
            {
                continue;
            }

            mListViewCategory->append(category, app);
        }
    }
}

/* static */ ManagerView *ManagerView::Instance()
{
    QMutexLocker locker(&mMutex);

    if (!mInstance)
    {
        mInstance = new ManagerView;
    }

    return mInstance;
}

void ManagerView::SetClientSQL(Client::ClientSQL &aClientSQL)
{
    mClientSQL = &aClientSQL;
    InitializeApps();
}

void ManagerView::SetHotReload(const std::function<void()> &aHotReload)
{
    mHotReload = aHotReload;
}

void ManagerView::GetListViewCategory(ListViewCategory *aListViewCategory)
{
    mListViewCategory = aListViewCategory;
}

void ManagerView::GetListViewPackage(ListViewPackage *aListViewPackage)
{
    mListViewPackage = aListViewPackage;
}

void ManagerView::PackageAppend(const Model::App &aApp)
{
    mListViewPackage->append(aApp);
}

void ManagerView::PackageRemove(const Model::App &aApp)
{
    mListViewPackage->remove(aApp);
}

void ManagerView::HotReload()
{
    mHotReload();
}
} // namespace View
