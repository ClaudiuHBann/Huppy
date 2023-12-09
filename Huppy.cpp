#include "pch.h"
#include "Huppy.h"

#include "View/ListViewApp.h"

#define QML_REGISTER_TYPE(type) qmlRegisterType<type>(QML_HUPPY_URI, 1, 0, #type);

constexpr auto QML_HUPPY_URI = "Huppy.QML";
constexpr auto QML_MAIN = "qrc:/QML/Main.qml";

using namespace View;

Huppy::Huppy(int &aArgc, char **aArgv)
    : mApp(aArgc, aArgv), mEngine(mApp.parent()), mClientSQL(mApp.parent()), mFileDownloader(mApp.parent()),
      mManagerView(mEngine, mClientSQL, mApp.parent())
{
    Initialize();
}

void Huppy::Initialize()
{
    InitializeQML();

    mEngine.load(QML_MAIN);
    Q_ASSERT_X(!mEngine.rootObjects().isEmpty(), "function", mEngine.catchError().toString().toLatin1().constData());

    mManagerView.Initialize();
}

void Huppy::InitializeQML()
{
    QML_REGISTER_TYPE(ListViewApp);
}

int Huppy::Run()
{
    return mApp.exec();
}
