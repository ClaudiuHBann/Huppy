#include "Huppy.h"

#define PATH_QML_MAIN "qrc:/Main.qml"
#define PATH_QML_MAIN_SL QStringLiteral(PATH_QML_MAIN)

Huppy::Huppy(int &aArgc, char **aArgv) : mApp(aArgc, aArgv), mInitialized(Initialize())
{
}

bool Huppy::Initialize()
{
    mEngine.load(PATH_QML_MAIN_SL);
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
