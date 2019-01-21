#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <Gemini.h>


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //QML上下文属性设置
    /*
    QQuickView view;
    Gemini gemini;
    view.rootContext()->setConntexProperty("gemini",&gemini);
    */

    //这里把Gemini类注册（qmlRegisterType）到了Qt元对象系统，
    //当然也可以先实例化再设置为QML上下文属性
    qmlRegisterType<Gemini>("Union.Lotto.Gemini", 1, 0, "Gemini");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

