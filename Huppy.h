#pragma once

#include <qguiapplication.h>
#include <qqmlapplicationengine.h>

#include "Client/ClientSQL.h"
#include "Client/FileDownloader.h"

class Huppy
{
  public:
    Huppy(int &aArgc, char **aArgv);

    void Initialize();
    void InitializeQML();
    int Run();

  private:
    QGuiApplication mApp;
    QObject *mParent{};
    QQmlApplicationEngine mEngine{};

    Client::ClientSQL mClientSQL;
    Client::FileDownloader mFileDownloader;
};
