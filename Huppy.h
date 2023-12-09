#pragma once

#include <qguiapplication.h>
#include <qqmlapplicationengine.h>

#include "Client/ClientSQL.h"
#include "Client/FileDownloader.h"

#include "View/ManagerView.h"

class Huppy
{
  public:
    Huppy(int &aArgc, char **aArgv);

    void Initialize();
    void InitializeQML();
    int Run();

  private:
    QGuiApplication mApp;
    QQmlApplicationEngine mEngine{};

    Client::ClientSQL mClientSQL;
    Client::FileDownloader mFileDownloader;

    View::ManagerView mManagerView;
};
