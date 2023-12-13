#include "pch.h"
#include "Huppy.h"

#include "View/ListViewApp.h"
#include "View/ListViewCategory.h"
#include "View/ListViewPackage.h"
#include "View/ManagerView.h"

#define QML_REGISTER_TYPE(type) qmlRegisterType<type>(QML_HUPPY_URI, 1, 0, #type);
#define QML_REGISTER_TYPE_SINGLETON(type) qmlRegisterSingletonType<type>(QML_HUPPY_URI, 1, 0, #type, &type::Initialize);

#ifdef _DEBUG
constexpr auto QML_MAIN = R"(C:\Users\Claudiu HBann\Desktop\Projects\C++\Huppy\QML\Main.qml)";
#else
constexpr auto QML_MAIN = "qrc:/QML/Main.qml";
#endif // _DEBUG

constexpr auto QML_HUPPY_URI = "Huppy.QML";

using namespace View;
using namespace Model;

Huppy::Huppy(int &aArgc, char **aArgv)
    : mApp(aArgc, aArgv), mEngine(mApp.parent()), mClientSQL(mApp.parent()), mFileDownloader(mApp.parent())
{
    Initialize();
}

void Huppy::Initialize()
{
    QML_REGISTER_TYPE(ListViewApp);
    QML_REGISTER_TYPE(ListViewPackage);
    QML_REGISTER_TYPE(ListViewCategory);

    QML_REGISTER_TYPE_SINGLETON(ManagerView);

    Load();

    ManagerView::Instance()->SetClientSQL(mClientSQL);
    ManagerView::Instance()->SetHotReload(std::bind(&Huppy::HotReload, this));
}

void Huppy::Load()
{
    mEngine.load(QML_MAIN);
    Q_ASSERT_X(!mEngine.rootObjects().isEmpty(), "function", mEngine.catchError().toString().toLatin1().constData());
}

void Huppy::HotReload()
{
    mEngine.clearComponentCache();
    mEngine.trimComponentCache();

    Load();
    ManagerView::Instance()->InitializeApps();
}

int Huppy::Run()
{
    return mApp.exec();
}
