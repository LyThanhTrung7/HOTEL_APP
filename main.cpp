#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "databasehotel.h"
#include "actionhotel.h"
#include "menu1.h"
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;
    DataBaseHotel data;
    data.loadRoomsFromDatabase();  // Tải dữ liệu phòng từ cơ sở dữ liệu

    // Khởi tạo ActionHotel với đối tượng DataBaseHotel
    ActionHotel hotel(data);

    menu1 MENU1;

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
    context->setContextProperty("HOTEL",&hotel);
    context->setContextProperty("MENU1",&MENU1);
    return app.exec();
}
