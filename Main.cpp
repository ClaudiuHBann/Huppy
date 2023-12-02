#include <QGuiApplication>
#include <QQmlApplicationEngine>

#define PATH_QML_MAIN "qrc:/qt/qml/huppy/Main.qml"
#define PATH_QML_MAIN_SL QStringLiteral(PATH_QML_MAIN)

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine(PATH_QML_MAIN_SL);
    if (engine.rootObjects().isEmpty())
    {
        return -1;
    }

    return app.exec();
}
