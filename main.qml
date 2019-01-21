import QtQuick 2.3
import QtQuick.Window 2.2


import Union.Lotto.Gemini 1.0
//Gemini类注册到Qt元对象系统后，并且在QML文件中导入（import），
//关键字Gemini就可以在当前QML文件中当作一种QML类型来用了。
//例子中有个MouseArea，单击鼠标时会发送begin()信号，
//进而调用doSomething()槽函数。

Window {
    visible: true;
    width:360;
    height: 360;
    title: "Union Lotto Game";
    color: "white";
    //在QML中使用枚举类型的方式是<CLASS_NAME>.<ENUM_VALUE>，
    //例如Gemini.BALL_COLOR_RED

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Gemini.begin();
            //Gemini类中添加了成员函数stop()，
            //在QML中访问的前提是public或protected成员函数，
            //且使用Q_INVOKABLE宏，位置在函数返回类型的前面。
            Gemini.stop();

            Gemini.ballNumber=10;
            //Qt.quit();
        }
    }
    Gemini{
        id:gemini
        onBegin: doSomething(gemini.BALL_COLOR_RED)
        //Gemini类中的ballNumber属性可以在QML中访问，修改，
        //访问时调用了ballNuber()函数，
        //修改时调用了setNumber()函数，
        //同时还发送了一个信号来自动更新这个属性值
        onBallNumberChanged: console.log("new ball number is", ballNumber) // 10
        Component.onCompleted: console.log("default ball number is", ballNumber) // 0
    }
    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}

