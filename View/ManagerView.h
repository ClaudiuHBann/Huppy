#pragma once

#include <qqmlapplicationengine.h>

#include <qmutex.h>

#include "Client/ClientSQL.h"

#include "ListViewApp.h"
#include "ListViewCategory.h"

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

    void SetClientSQL(Client::ClientSQL &aClientSQL);

    Q_INVOKABLE void GetListViewCategory(ListViewCategory *aListViewCategory);

  private:
    static inline QMutex mMutex{};
    static inline ManagerView *mInstance{};

    Client::ClientSQL *mClientSQL{};

    ListViewCategory *mListViewCategory{};

    void InitializeApps();
};
} // namespace View
