import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts

Rectangle{
    id: check_in
    width: 800
    height: 400
    anchors.horizontalCenter: parent.horizontalCenter
    y: 150
    radius: 50
    property int type: 0
    Text{
        id: checkIn
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: check_in.top
        anchors.margins: 10
        text: "CHECK-IN"
        font.pointSize: 20
        font.bold: true
    }
    Column{
        id: menucheck_in
        anchors{
            horizontalCenter: parent.horizontalCenter
            topMargin: 20
            top: checkIn.bottom
        }
        ComboBox{
            id: select_room
            width: 200
            height: 30
            currentIndex: 0
            model: select_roomListModel
            anchors.horizontalCenter: menucheck_in.horizontalCenter

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
                    check_in.type = 1;
                } else if (select_room.currentIndex === 2) {
                    check_in.type = 2;
                }else if (select_room.currentIndex === 3) {
                    check_in.type = 3;
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
                    horizontalCenter: menucheck_in.horizontalCenter
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
                    horizontalCenter: menucheck_in.horizontalCenter
                }
            }
            TextField{
                id: customer_phone
                placeholderText: "Enter customer phone number"
                placeholderTextColor: "#807B72"
                color: "black"
                width: 200
                height: 30
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 13
                leftPadding: 10
                background: Rectangle {
                    color: customer_phone.focus ? "#B9B09D":"white"
                    radius: 5
                    border.color: "black"
                    border.width: 1
                }
                anchors{
                    top: customer_name.bottom
                    topMargin: 20
                    horizontalCenter: menucheck_in.horizontalCenter
                }
            }
            Button{
                id: bt_checkin
                width: 100
                height: 25
                anchors{
                    top:customer_phone.bottom
                    topMargin: 20
                    horizontalCenter: customer_phone.horizontalCenter
                }
                Text{
                    text: "Check-In"
                    color: 	"black"
                    anchors.centerIn: bt_checkin
                    font.pointSize: 13
                }
                background: Rectangle{
                    color: bt_checkin.pressed ?"white":"#E4B14D"
                    radius: 10
                    border.width: 1
                }
                onClicked: {
                    var number = parseInt(room_number.text);
                    dbManager.checkInOut(number,customer_name.text,check_in.type, customer_phone.text,0);
                }
            }
            Text{
                id: note_checkin
                text:dbManager.checkIn
                anchors{
                    top:bt_checkin.bottom
                    topMargin: 20
                    horizontalCenter: customer_phone.horizontalCenter
                }
            }
        }

    }
}
