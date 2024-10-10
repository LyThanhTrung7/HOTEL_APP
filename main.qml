import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls
import QtQuick.Layouts
import "ui/Room"
import "ui/CheckIn"
import"ui/Booking"
import"ui/CheckOut"
import"ui/History"
Window {
    width: 1280
    height: 640
    visible: true
    title: qsTr("HOTEL APP")

    property int menu: 0
    Image {
        id: background
        source: "qrc:/image/Background.jpg"
        height: parent.height
        width: parent.width
    }
    Rectangle{
        id:topMain
        height: 60
        width: 750
        anchors{
            horizontalCenter: parent.horizontalCenter
            top: parent.top
            topMargin: 50
        }
        radius: 50
        Image {
            id: img_room
            anchors{
                left: topMain.left
                leftMargin: 50
            }
            source: "qrc:/image/bedroom.png"
            width: 50
            height: 40
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    menu = 1;
                }
            }
        }
        Text{
            id: room
            text: "ROOM"
            anchors{
                top: img_room.bottom
                left: topMain.left
                leftMargin: 55
            }
            font.bold: true

        }
        Image {
            id: img_checkIn
            anchors{
                left: room.left
                leftMargin: 150
            }
            source: "qrc:/image/check-in.png"
            width: 40
            height: 40
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    menu = 2;
                }
            }
        }
        Text{
            id: checkin
            text: "CHECK-IN"
            anchors{
                top: img_checkIn.bottom
                left: room.left
                leftMargin: 150
            }
            font.bold: true
        }
        Image {
            id: img_booking
            anchors{
                left: img_checkIn.left
                leftMargin: 150
            }
            source: "qrc:/image/booking.png"
            width: 40
            height: 40
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    menu = 3;
                }
            }
        }
        Text{
            id: booking
            text: "BOOKING"
            anchors{
                top: img_booking.bottom
                left: img_checkIn.left
                leftMargin: 150
            }
            font.bold: true
        }

        Image {
            id: img_checkOut
            anchors{
                left: img_booking.left
                leftMargin: 150
            }
            source: "qrc:/image/check-out.png"
            width: 40
            height: 40
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    menu = 4;
                }
            }
        }
        Text{
            id: checkout
            text: "CHECK-OUT"
            anchors{
                top: img_checkOut.bottom
                left: img_booking.left
                leftMargin: 150
            }
            font.bold: true
        }
        Image {
            id: img_history
            anchors{
                left: img_checkOut.left
                leftMargin: 150
            }
            source: "qrc:/image/history-book.png"
            width: 40
            height: 40
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    menu = 5;
                    dbManager.getHistory();
                }
            }
        }
        Text{
            id: history
            text: "HISTORY"
            anchors{
                top: img_history.bottom
                left: img_checkOut.left
                leftMargin: 148
            }
            font.bold: true
        }
    }

    Rectangle{
        id: bell
        anchors{
            right: parent.right
            rightMargin: 50
            top: parent.top
            topMargin: 50
        }
        width: 60
        height: 60
        radius: 20
        Image {
            source: "qrc:/image/notification-bell.png"
            anchors.centerIn: bell
            width: 40
            height: 40
        }
    }
    Text{
        id: clock
        anchors{
            left: parent.left
            top:  parent.top
            margins: 50
        }
        color: "white"
        font.pointSize: 20
        text: MENU1.currentTime
        font.bold: true
    }
    Room{
        id: rooms
        visible: menu == 1
    }
    CheckIn{
        id: check_in
        visible: menu == 2

    }
    Booking{
        id: id_booking
        visible: menu == 3
    }
    CheckOut{
        id: id_Checkout
        visible: menu == 4

    }
    History{
        id: id_History
        visible: menu == 5
    }

}

