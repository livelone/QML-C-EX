#ifndef GEMINI
#define GEMINI

#include <QObject>
#include <QDebug>
class Gemini : public QObject
{
    //Gemini类中的信号begin()和槽doSomething()都可以被QML访问。
    //槽必须声明为public或protected，信号在C++中使用时要用到emit关键字，
    //但在QML中就是个普通的函数，用法同函数一样，信号处理器形式为on<Signal>，
    //Signal首字母大写。信号不支持重载，
    //多个信号的名字相同而参数不同时，能够被识别的只是最后一个信号，与信号的参数无关。

    Q_OBJECT
signals:
    void begin();
public slots:
    void doSomething() {
        qDebug() << "Gemini::doSomething() called";
    }
};

#endif // GEMINI

