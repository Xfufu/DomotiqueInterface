/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "HttpConnection.h"
#include "ObjectList.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    HttpConnection connection;
    connection.init();
    ObjectList objectList(engine.rootContext(), connection);

    engine.rootContext()->setContextProperty("objectList", &objectList);
    objectList.init();
    return app.exec();
}
