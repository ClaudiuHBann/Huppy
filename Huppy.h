#pragma once

#include <qguiapplication.h>
#include <qqmlapplicationengine.h>

#include "Client/ClientSQL.h"
#include "Client/FileDownloader.h"

class Huppy
{
  public:
    Huppy(int &aArgc, char **aArgv);

    bool Initialize();
    int Run();

  private:
    QGuiApplication mApp;
    QObject *mParent{};
    QQmlApplicationEngine mEngine{};

    bool mInitialized{};

    Client::ClientSQL mClientSQL;
    Client::FileDownloader mFileDownloader;
};
