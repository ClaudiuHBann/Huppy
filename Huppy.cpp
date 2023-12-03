#include "pch.h"
#include "Huppy.h"

using namespace Client;

constexpr auto PATH_QML_MAIN = "qrc:/Main.qml";

Huppy::Huppy(int &aArgc, char **aArgv)
    : mApp(aArgc, aArgv), mParent(mApp.parent()), mEngine(mParent), mInitialized(Initialize()), mClientSQL(mParent),
      mFileDownloader(mParent)
{
}

bool Huppy::Initialize()
{
    mEngine.load(PATH_QML_MAIN);
    if (mEngine.rootObjects().isEmpty())
    {
        return false;
    }

    return true;
}

int Huppy::Run()
{
    return mInitialized ? mApp.exec() : -1;
}
