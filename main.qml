import QtQuick 2.3
import QtQuick.Window 2.2


import Union.Lotto.Gemini 1.0
//Gemini类注册到Qt元对象系统后，并且在QML文件中导入（import），
//关键字Gemini就可以在当前QML文件中当作一种QML类型来用了。
//例子中有个MouseArea，单击鼠标时会发送begin()信号，
//进而调用doSomething()槽函数。

Window {
    visible: true

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Gemini.begin();
            Qt.quit();
        }
    }

    Gemini{
        id:gemini
        onBegin: doSomething()
    }
    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
}

