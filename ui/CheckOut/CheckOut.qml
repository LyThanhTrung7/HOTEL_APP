import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

Rectangle{
    id: check_out
    width: 800
    height: 400
    anchors.horizontalCenter: parent.horizontalCenter
    y: 150
    radius: 50
    property string type: ""
    property bool checkout: false

    Text{
        id: checkOut
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.margins: 10
        text: "CHECK-OUT"
        font.pointSize: 20
        font.bold: true
    }
    Column{
        id: menucheck_out
        anchors{
            horizontalCenter: parent.horizontalCenter
            topMargin: 20
            top: checkOut.bottom
        }
        ComboBox{
            id: select_room
            width: 200
            height: 30
            currentIndex: 0
            model: select_roomListModel
            anchors.horizontalCenter: menucheck_out.horizontalCenter

            ListModel{
                id: select_roomListModel
                ListElement{
                    key: "Type Room"
                }
                ListElement{
                    key: "1/Twin Room"
                }
                ListElement{
                    key: "2/Triple Room"
                }
                ListElement{
                    key: "3/Vip Room"
                }
            }
            contentItem: Text{
                text: select_room.displayText
                font.pointSize: 13
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "black"
            }
            onActivated: {
                if (select_room.currentIndex === 1) {
                    check_in.type = "Twin Room";
                } else if (select_room.currentIndex === 2) {
                    check_in.type = "Triple Room";
                }else if (select_room.currentIndex === 3) {
                    check_in.type = "Vip Room";
                }
            }
        }
        TextField{
            id: room_number
            placeholderText: "Enter room number"
            placeholderTextColor: "#807B72"
            color: "black"
            width: 200
            height: 30
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 13
            leftPadding: 10
            background: Rectangle {
                color: room_number.focus ? "#B9B09D":"white"
                radius: 5
                border.color: "black"
                border.width: 1
            }
            anchors{
                top: select_room.bottom
                topMargin: 20
                horizontalCenter: menucheck_out.horizontalCenter
            }
        }
        TextField{
            id: customer_name
            placeholderText: "Enter customer name"
            placeholderTextColor: "#807B72"
            color: "black"
            width: 200
            height: 30
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 13
            leftPadding: 10
            background: Rectangle {
                color: customer_name.focus ? "#B9B09D":"white"
                radius: 5
                border.color: "black"
                border.width: 1
            }
            anchors{
                top: room_number.bottom
                topMargin: 20
                horizontalCenter: menucheck_out.horizontalCenter
            }
        }
        TextField{
            id: customer_note
            placeholderText: "Enter customer notes"
            placeholderTextColor: "#807B72"
            color: "black"
            width: 200
            height: 30
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 13
            leftPadding: 10
            background: Rectangle {
                color: customer_note.focus ? "#B9B09D":"white"
                radius: 5
                border.color: "black"
                border.width: 1
            }
            anchors{
                top: customer_name.bottom
                topMargin: 20
                horizontalCenter: menucheck_out.horizontalCenter
            }
        }
        Button{
            id: bt_checkout
            width: 100
            height: 25
            anchors{
                top:customer_note.bottom
                topMargin: 20
                horizontalCenter: customer_note.horizontalCenter
            }
            Text{
                text: "Check-Out"
                color: 	"black"
                anchors.centerIn: bt_checkout
                font.pointSize: 13
            }
            background: Rectangle{
                color: bt_checkout.pressed ?"white":"#E4B14D"
                radius: 10
                border.width: 1
            }
            onClicked: {
                var number = parseInt(room_number.text);
                HOTEL.checkout(number,check_in.type);
                check_out.checkout = true;
            }
        }
        Rectangle {
            id: note_checkout
            width: 500
            height: 300
            radius: 20
            color: "#E4B14D"
            border.color: "black"
            visible: checkout
            anchors.top: checkOut.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            Text {
                anchors.centerIn: parent
                color: "black"
                text:HOTEL.status
                font.bold: true
                font.pointSize: 16
            }
            Button{
                id: bt_return
                width: 100
                height: 30
                anchors{
                bottom: note_checkout.bottom;
                margins: 10;
                horizontalCenter: parent.horizontalCenter
                }
                Text{
                    text: "Return"
                    color: 	"black"
                    anchors.centerIn: bt_return
                    font.pointSize: 13
                }
                background: Rectangle{
                    color: bt_return.pressed ?"#E4B14D":"white"
                    radius: 10
                    border.color: "black"
                    border.width: 1
                }
                onClicked: {
                   check_out.checkout = false;
                   HOTEL.status = "";
                   customer_name = "";
                   customer_note = "";
                   room_number = "";
                   check_in.type = "";
                }
            }
        }
    }
}
