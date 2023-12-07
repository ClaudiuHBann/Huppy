#include "pch.h"
#include "Huppy.h"

#include "View/ListViewApp.h"

using namespace View;

constexpr auto PATH_QML_MAIN = "qrc:/QML/Main.qml";

Huppy::Huppy(int &aArgc, char **aArgv)
    : mApp(aArgc, aArgv), mParent(mApp.parent()), mEngine(mParent), mClientSQL(mParent), mFileDownloader(mParent)
{
    Initialize();
}

void Huppy::Initialize()
{
    qmlRegisterType<ListViewApp>("Huppy.QML.Types", 1, 0, "ListViewApp");

    mEngine.load(PATH_QML_MAIN);
    Q_ASSERT_X(!mEngine.rootObjects().isEmpty(), "function", mEngine.catchError().toString().toStdString().c_str());
}

int Huppy::Run()
{
    return mApp.exec();
}
