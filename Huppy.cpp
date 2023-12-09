#include "pch.h"
#include "Huppy.h"

#include "View/ListViewApp.h"
#include "View/ListViewCategory.h"

#include "View/ManagerView.h"

#define QML_REGISTER_TYPE(type) qmlRegisterType<type>(QML_HUPPY_URI, 1, 0, #type);
#define QML_REGISTER_TYPE_META(type) qRegisterMetaType<type>(#type);
#define QML_REGISTER_TYPE_SINGLETON(type) qmlRegisterSingletonType<type>(QML_HUPPY_URI, 1, 0, #type, &type::Initialize);

constexpr auto QML_HUPPY_URI = "Huppy.QML";
constexpr auto QML_MAIN = "qrc:/QML/Main.qml";

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
    QML_REGISTER_TYPE(ListViewCategory);

    QML_REGISTER_TYPE_META(App);
    QML_REGISTER_TYPE_META(Category);

    QML_REGISTER_TYPE_SINGLETON(ManagerView);

    mEngine.load(QML_MAIN);
    Q_ASSERT_X(!mEngine.rootObjects().isEmpty(), "function", mEngine.catchError().toString().toLatin1().constData());

    ManagerView::Instance()->SetClientSQL(mClientSQL);
}

int Huppy::Run()
{
    return mApp.exec();
}
