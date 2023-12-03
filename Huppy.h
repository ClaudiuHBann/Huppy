#pragma once

#include <qguiapplication.h>
#include <qqmlapplicationengine.h>

class Huppy
{
  public:
    Huppy(int &aArgc, char **aArgv);

    bool Initialize();
    int Run();

  private:
    QGuiApplication mApp;
    QQmlApplicationEngine mEngine{};

    bool mInitialized{};
};
