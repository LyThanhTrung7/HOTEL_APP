#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <menu1.h>
#include <QQmlContext>
#include "database_hotel.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    menu1 Menu1;
    Database_Hotel dbManager;

    QQmlApplicationEngine engine;
    dbManager.getData();
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    QQmlContext * context (engine.rootContext());
    context->setContextProperty("MENU1",&Menu1);
    context->setContextProperty("dbManager", &dbManager);
    return app.exec();
}
