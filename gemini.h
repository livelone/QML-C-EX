#ifndef GEMINI_H
#define GEMINI_H

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
    Q_ENUMS(BALL_COLOR)

    //Gemini类中添加了Q_PROPERTY()宏，
    //用来在QObject派生类中声明属性，这个属性如同类的数据成员一样，
    //但它又有一些额外的特性可通过Qt元对象系统来访问
    Q_PROPERTY(unsigned int ballNumber READ ballNumber WRITE setBallNumber NOTIFY ballNumberChanged)

public:
    Gemini():m_ballColor(BALL_COLOR_YELLOW),m_ballNumber(0){
        qDebug()<< "Gemini::Gemini()called";
    }
    //添加了BALL_COLOR枚举类型，要想在QML中使用，就用到了Q_ENUMS()宏
    enum BALL_COLOR{
        BALL_COLOR_YELLOW,
        BALL_COLOR_RED,
        BALL_COLOR_BLUE,
        BALL_COLOR_ALL
    };

    unsigned int ballNumber() const{
        return m_ballNumber;
    }
    void setBallNumber(const unsigned int &ballNumber) {
        if(ballNumber != m_ballNumber) {
            m_ballNumber = ballNumber;
            emit ballNumberChanged();
        }
    }

    //Gemini类中添加了成员函数stop()，
    //在QML中访问的前提是public或protected成员函数，
    //且使用Q_INVOKABLE宏，位置在函数返回类型的前面。
    Q_INVOKABLE void stop(){
        qDebug()<< "Gemini::stop()called";
    }


signals:
    void begin();

    void ballNumberChanged();

public slots:
    void doSomething(BALL_COLOR ballColor) {
        qDebug() << "Gemini::doSomething() called with"<<ballColor;
        if(ballColor!=m_ballColor){
            m_ballColor =ballColor;
            qDebug() << "ball color changed";
        }
    }

private:
    BALL_COLOR m_ballColor;
    unsigned int  m_ballNumber;
};

#endif // GEMINI

