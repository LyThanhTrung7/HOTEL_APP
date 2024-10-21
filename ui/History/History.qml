import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

Rectangle{
    id: history
    width: 840
    height: 400
    anchors.horizontalCenter: parent.horizontalCenter
    y: 150
    radius: 50

    ComboBox{
        anchors{
            left:history.left
            leftMargin: 30
            top:history.top
            topMargin: 20
        }
        id: select_view
        width: 120
        height: 25
        currentIndex: 0
        model: select_viewListModel
        x: 10
        ListModel{
            id: select_viewListModel
            ListElement{
                key: "Oldest"
            }
            ListElement{
                key: "Latest"
            }
        }
        contentItem: Text{
            text: select_view.displayText
            font.pointSize: 12
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            color: "black"
        }
        onActivated: {
            // if (select_view.currentIndex === 0) {
            //     myMenu.user_his(0);
            // } else if (select_view.currentIndex === 1) {
            //     myMenu.user_his(1);
            // }
        }
    }
    Text{
        id: all_room
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: history.top
        anchors.margins: 10
        text: "HISTORY"
        font.pointSize: 20
        font.bold: true
    }

    ScrollView {
        id: scrollView
        width: 780
        height: 320
        anchors {
            top: all_room.bottom
            topMargin: 10
            horizontalCenter: history.horizontalCenter
        }
        contentWidth: column.width
        contentHeight: column.height

        Column {
            id: column
            width: scrollView.width

            RowLayout {
                spacing: 2
                Layout.fillWidth: true
                Rectangle { width: 50; height: 40; color: "#E4B14D"; border.color: "black"
                    Text { anchors.centerIn: parent; text: "Room"; font.bold: true }
                }
                Rectangle { width: 100; height: 40; color: "#E4B14D"; border.color: "black"
                    Text { anchors.centerIn: parent; text: "Type"; font.bold: true }
                }
                Rectangle { width: 100; height: 40; color: "#E4B14D"; border.color: "black"
                    Text { anchors.centerIn: parent; text: "Name"; font.bold: true }
                }
                Rectangle { width: 100; height: 40; color: "#E4B14D"; border.color: "black"
                    Text { anchors.centerIn: parent; text: "Phone"; font.bold: true }
                }
                Rectangle { width: 150; height: 40; color: "#E4B14D"; border.color: "black"
                    Text { anchors.centerIn: parent; text: "Check In"; font.bold: true }
                }
                Rectangle { width: 150; height: 40; color: "#E4B14D"; border.color: "black"
                    Text { anchors.centerIn: parent; text: "Check Out"; font.bold: true }
                }
                Rectangle { width: 100; height: 40; color: "#E4B14D"; border.color: "black"
                    Text { anchors.centerIn: parent; text: "Revenue"; font.bold: true }
                }
            }
            Repeater {
                id: list
                model: HOTEL.his
                RowLayout {
                    spacing: 2
                    Rectangle { width: 50; height: 40; color: "#FAD58B"; border.color: "black"
                        Text { anchors.centerIn: parent; text: modelData.ROOM_NUMBER }
                    }
                    Rectangle { width: 100; height: 40; color: "#FAD58B"; border.color: "black"
                        Text { anchors.centerIn: parent; text: modelData.TYPE_ROOM }
                    }
                    Rectangle { width: 100; height: 40; color: "#FAD58B"; border.color: "black"
                        Text { anchors.centerIn: parent; text: modelData.CUS_NAME }
                    }
                    Rectangle { width: 100; height: 40; color: "#FAD58B"; border.color: "black"
                        Text { anchors.centerIn: parent; text: modelData.CUS_NUMBER }
                    }
                    Rectangle { width: 150; height: 40; color: "#FAD58B"; border.color: "black"
                        Text { anchors.centerIn: parent; text: modelData.TIME_CHECKIN }
                    }
                    Rectangle { width: 150; height: 40; color: "#FAD58B"; border.color: "black"
                        Text { anchors.centerIn: parent; text: modelData.TIME_CHECKOUT }
                    }
                    Rectangle { width: 100; height: 40; color: "#FAD58B"; border.color: "black"
                        Text { anchors.centerIn: parent; text: modelData.REVENUE }
                    }
                }
            }
        }
    }

}
