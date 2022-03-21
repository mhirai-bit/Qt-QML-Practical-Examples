#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include "documentcontroller.h"


int main(int argc, char *argv[])
{
    qputenv("QT_IM_MODULE", QByteArray("qtvirtualkeyboard"));

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication app(argc, argv);
    QGuiApplication::setApplicationName("Notepad Example");
    QGuiApplication::setOrganizationName("Tutorial");
    QGuiApplication::setOrganizationDomain("tutorial");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    qmlRegisterType<DocumentController>("notepad.example.texteditor", 1, 0, "DocumentController");
    engine.load(url);

    return app.exec();
}
