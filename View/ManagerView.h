#pragma once

#include <qqmlapplicationengine.h>

#include <qmutex.h>

#include "Client/ClientSQL.h"

#include "ListViewApp.h"
#include "ListViewCategory.h"
#include "ListViewPackage.h"

namespace View
{
class ManagerView : public QObject
{
    Q_OBJECT;
    QML_ELEMENT;
    QML_SINGLETON;

  public:
    static ManagerView *Instance();

    static QObject *Initialize(QQmlEngine *, QJSEngine *)
    {
        return Instance();
    }
    void InitializeApps();

    void SetClientSQL(Client::ClientSQL &aClientSQL);

    void SetHotReload(const std::function<void()> &aHotReload);
    Q_INVOKABLE void HotReload();

    Q_INVOKABLE void GetListViewCategory(ListViewCategory *aListViewCategory);
    Q_INVOKABLE void GetListViewPackage(ListViewPackage *aListViewPackage);

    Q_INVOKABLE void PackageAppend(const Model::App &aApp);
    Q_INVOKABLE void PackageRemove(const Model::App &aApp);

  private:
    static inline QMutex mMutex{};
    static inline ManagerView *mInstance{};

    Client::ClientSQL *mClientSQL{};

    std::function<void()> mHotReload{};

    ListViewCategory *mListViewCategory{};
    ListViewPackage *mListViewPackage{};
};
} // namespace View
