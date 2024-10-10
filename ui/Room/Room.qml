import QtQuick 2.15

Rectangle{
    id: room
    width: 800
    height: 400
    anchors.horizontalCenter: parent.horizontalCenter
    y: 150
    radius: 50
    property bool showInfo: false

    Text{
        id: all_room
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: room.top
        anchors.margins: 10
        text: "ROOM AVAILABILITY"
        font.pointSize: 20
        font.bold: true
    }
    Text{
        id: available
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.leftMargin: 40
        anchors.topMargin: 20
        text: "Available"
        font.pointSize: 10
        font.bold: true
    }
    Rectangle{
        height: 20
        width: 20
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.topMargin: 20
        border.color: "black"
        radius: 5
        color: "#E4B14D"
    }

    Row{
        id: row1
        anchors{
            left: room.left
            top: all_room.bottom
            topMargin: 10
            margins: 40
        }
        spacing: 30
        Repeater {
            model: 8
            Rectangle {
                width: 64
                height: 64
                radius: 10
                color:dbManager.checkRoom(101 + model.index) ? "white" : "#E4B14D"
                border.color: "black"
                Text {
                    anchors.centerIn: parent
                    color: "black"
                    text: qsTr("%1").arg(model.index + 101)
                    font.bold: true
                    font.pointSize: 14
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        showInfo = !showInfo;
                        dbManager.printDataRoom(101 + model.index);
                    }
                }
            }
        }
    }
    Row{
        id: row2
        anchors{
            left: room.left
            top: row1.top
            topMargin: 80
            leftMargin: 40
        }
        spacing: 30
        Repeater {
            model: 8
            Rectangle {
                width: 64
                height: 64
                radius: 10
                color: dbManager.checkRoom(201 + model.index) ? "white" : "#E4B14D"
                border.color: "black"
                Text {
                    anchors.centerIn: parent
                    color: "black"
                    text: qsTr("%1").arg(model.index + 201)
                    font.bold: true
                    font.pointSize: 14
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        showInfo = !showInfo;
                        dbManager.printDataRoom(201 + model.index);
                    }
                }
            }
        }
    }
    Row{
        id: row3
        anchors{
            left: room.left
            top: row2.top
            topMargin: 80
            leftMargin: 40
        }
        spacing: 30
        Repeater {
            model: 8
            Rectangle {
                width: 64
                height: 64
                radius: 10
                color:dbManager.checkRoom(301 + model.index) ? "white" : "#E4B14D"
                border.color: "black"
                Text {
                    anchors.centerIn: parent
                    color: "black"
                    text: qsTr("%1").arg(model.index + 301)
                    font.bold: true
                    font.pointSize: 14
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        showInfo = !showInfo;
                        dbManager.printDataRoom(301 + model.index);
                    }
                }
            }
        }
    }
    Row{
        id: row4
        anchors{
            left: room.left
            top: row3.top
            topMargin: 80
            leftMargin: 40
        }
        spacing: 30
        Repeater {
            model: 8
            Rectangle {
                width: 64
                height: 64
                radius: 10
                color:dbManager.checkRoom(401 + model.index) ? "white" : "#E4B14D"
                border.color: "black"
                Text {
                    anchors.centerIn: parent
                    color: "black"
                    text: qsTr("%1").arg(model.index + 401)
                    font.bold: true
                    font.pointSize: 14
                }
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        showInfo = !showInfo;
                        dbManager.printDataRoom(401 + model.index);
                    }
                }
            }
        }
    }
    Rectangle {
        id: infor
        width: 400
        height: 250
        radius: 20
        color: "#E4B14D"
        border.color: "black"
        visible: showInfo
        anchors.top: all_room.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        Text {
            anchors.centerIn: parent
            color: "black"
            text:dbManager.dataRoom
            font.bold: true
            font.pointSize: 16
        }
    }
}
