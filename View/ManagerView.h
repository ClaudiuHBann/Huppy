#pragma once

#include <qqmlapplicationengine.h>

#include "Client/ClientSQL.h"
#include "ListViewApp.h"

#include "Model/Category.h"

namespace View
{
class ManagerView : public QObject
{
    Q_OBJECT;

  public:
    ManagerView(QQmlApplicationEngine &aEngine, Client::ClientSQL &aClientSQL, QObject *aParent);

    void Initialize();
    void InitializeApps();

  private:
    QQmlApplicationEngine &mEngine;
    Client::ClientSQL &mClientSQL;

    ListViewApp *mListViewApp{};

    QMap<QString, QList<Model::App>> mCategoryToApps{};
};
} // namespace View
