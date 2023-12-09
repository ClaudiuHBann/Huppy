#include "pch.h"
#include "Huppy.h"

#include "View/ListViewApp.h"
#include "View/ListViewCategory.h"

#define QML_REGISTER_COMPONENT(component) qmlRegisterType<component>(QML_HUPPY_URI, 1, 0, #component);
#define QML_REGISTER_TYPE(type) qRegisterMetaType<type>(#type);

constexpr auto QML_HUPPY_URI = "Huppy.QML";
constexpr auto QML_MAIN = "qrc:/QML/Main.qml";

using namespace View;
using namespace Model;

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

void Huppy::InitializeTypes()
{
    QML_REGISTER_TYPE(App);
    QML_REGISTER_TYPE(Category);
}

void Huppy::InitializeQML()
{
    QML_REGISTER_COMPONENT(App);
    QML_REGISTER_COMPONENT(Category);
    QML_REGISTER_COMPONENT(ListViewApp);
    QML_REGISTER_COMPONENT(ListViewCategory);
}

int Huppy::Run()
{
    return mApp.exec();
}
