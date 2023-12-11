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
    void HotReload();
    void Load();

    int Run();

  private:
    QGuiApplication mApp;
    QQmlApplicationEngine mEngine{};

    Client::ClientSQL mClientSQL;
    Client::FileDownloader mFileDownloader;
};
