import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
Rectangle{
    id: booking
    width: 800
    height: 450
    anchors.horizontalCenter: parent.horizontalCenter
    y: 150
    radius: 50
    property int room: 0
    property int room1: 0
    property int room2: 0
    Text{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: booking.top
        anchors.margins: 10
        text: "BOOKING"
        font.pointSize: 20
        font.bold: true
    }
    Text{
        id: text_twin
        text: "Twin Room"
        font.bold: true
        font.pointSize: 13
        anchors{
            top: booking.top
            left: booking.left
            leftMargin: 60
            topMargin: 55
        }
    }
    Image{
        id: twin
        width: 200
        height: 130
        anchors{
            top: text_twin.bottom
            left: booking.left
            leftMargin: 60
            topMargin: 10
        }
        source: "qrc:/image/twin.png"
    }
    Column{
        id: twin_book
        anchors{
            topMargin: 10
            top: twin.bottom
            left: booking.left
            leftMargin: 60
        }
        ComboBox{
            id: select_room
            width: 200
            height: 30
            currentIndex: 0
            model: select_roomListModel

            ListModel{
                id: select_roomListModel
                ListElement{
                    key: "Select Room"
                }
                ListElement{
                    key: "101"
                }
                ListElement{
                    key: "102"
                }
                ListElement{
                    key: "103"
                }
                ListElement{
                    key: "201"
                }
                ListElement{
                    key: "203"
                }
                ListElement{
                    key: "206"
                }
                ListElement{
                    key: "301"
                }
                ListElement{
                    key: "302"
                }
                ListElement{
                    key: "303"
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
                    booking.room = 101;
                } else if (select_room.currentIndex === 2) {
                    booking.room = 102;
                }else if (select_room.currentIndex === 3) {
                    booking.room = 103;
                }else if (select_room.currentIndex === 4) {
                    booking.room = 201;
                } else if (select_room.currentIndex === 5) {
                    booking.room = 203;
                }else if (select_room.currentIndex === 6) {
                    booking.room = 206;
                }  else if (select_room.currentIndex === 7) {
                    booking.room = 301;
                } else if (select_room.currentIndex === 8) {
                    booking.room = 302;
                }else if (select_room.currentIndex === 9) {
                    booking.room = 303;
                }
            }
        }

        TextField{
            id: customer_name
            placeholderText: "Enter name"
            placeholderTextColor: "#807B72"
            color: "black"
            width: 200
            height: 30
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
            leftPadding: 10
            background: Rectangle {
                color: customer_name.focus ? "#B9B09D":"white"
                radius: 5
                border.color: "black"
                border.width: 1
            }
            anchors{
                top: select_room.bottom
                topMargin: 10
                horizontalCenter: twin.horizontalCenter
            }
        }
        TextField{
            id: customer_phone
            placeholderText: "Enter phone number"
            placeholderTextColor: "#807B72"
            color: "black"
            width: 200
            height: 30
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
            leftPadding: 10
            background: Rectangle {
                color: customer_phone.focus ? "#B9B09D":"white"
                radius: 5
                border.color: "black"
                border.width: 1
            }
            anchors{
                top: customer_name.bottom
                topMargin: 10
                horizontalCenter: twin.horizontalCenter
            }
        }
        Row{
            id: time_book
            anchors{
                top: customer_phone.bottom
                topMargin: 10
            }
            spacing: 10
            TextField{
                id: day
                placeholderText: "Day"
                placeholderTextColor: "#807B72"
                color: "black"
                width: 60
                height: 30
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 10
                leftPadding: 10
                background: Rectangle {
                    color: day.focus ? "#B9B09D":"white"
                    border.color: "black"
                    border.width: 1
                    radius: 5
                }
            }
            TextField{
                id: month
                placeholderText: "Month"
                placeholderTextColor: "#807B72"
                color: "black"
                width: 60
                height: 30
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 10
                leftPadding: 10
                background: Rectangle {
                    color: month.focus ? "#B9B09D":"white"
                    border.color: "black"
                    border.width: 1
                    radius: 5
                }
            }
            TextField{
                id: year
                placeholderText: "Year"
                placeholderTextColor: "#807B72"
                color: "black"
                width: 60
                height: 30
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 10
                leftPadding: 10
                background: Rectangle {
                    color: year.focus ? "#B9B09D":"white"
                    border.color: "black"
                    border.width: 1
                    radius: 5
                }
            }
        }
        Button{
            id: bt_booking
            width: 100
            height: 25
            anchors{
                top:time_book.bottom
                topMargin: 10
                horizontalCenter: time_book.horizontalCenter
            }
            Text{
                text: "Book"
                color: 	"black"
                anchors.centerIn: bt_booking
                font.pointSize: 10
            }
            background: Rectangle{
                color: bt_booking.pressed ?"white":"#E4B14D"
                radius: 10
                border.width: 1
            }
            onClicked: {
                dbManager.Booking(booking.room, customer_name.text,
                                  year.text+"-"+month.text+"-"+day.text, 1, customer_phone.text);
            }
        }
    }

    Text{
        id: text_triple
        text: "Triple Room"
        font.bold: true
        font.pointSize: 13
        anchors{
            top: booking.top
            left: twin.right
            leftMargin: 30
            topMargin: 55
        }
    }
    Image{
        id: triple
        width: 200
        height: 130
        anchors{
            top: text_triple.bottom
            left: twin.right
            leftMargin: 30
            topMargin: 10
        }
        source: "qrc:/image/triple.png"
    }
    Column{
        id: triple_book
        anchors{
            topMargin: 10
            top: triple.bottom
            left: twin.right
            leftMargin: 30
        }
        ComboBox{
            id: select_room1
            width: 200
            height: 30
            currentIndex: 0
            model: select_room1ListModel

            ListModel{
                id: select_room1ListModel
                ListElement{
                    key: "Select Room"
                }
                ListElement{
                    key: "104"
                }
                ListElement{
                    key: "105"
                }
                ListElement{
                    key: "204"
                }
                ListElement{
                    key: "205"
                }
                ListElement{
                    key: "304"
                }
                ListElement{
                    key: "305"
                }
                ListElement{
                    key: "404"
                }
                ListElement{
                    key: "405"
                }
            }
            contentItem: Text{
                text: select_room1.displayText
                font.pointSize: 13
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "black"
            }
            onActivated: {
                if (select_room1.currentIndex === 1) {
                    booking.room1 = 104;
                } else if (select_room1.currentIndex === 2) {
                    booking.room1 = 105;
                }else if (select_room1.currentIndex === 3) {
                    booking.room1 = 204;
                }else if (select_room1.currentIndex === 4) {
                    booking.room1 = 205;
                } else if (select_room1.currentIndex === 5) {
                    booking.room1 = 304;
                }else if (select_room1.currentIndex === 6) {
                    booking.room1 = 305;
                }  else if (select_room1.currentIndex === 7) {
                    booking.room1 = 404;
                } else if (select_room1.currentIndex === 8) {
                    booking.room1 = 405;
                }
            }

        }

        TextField{
            id: customer_name1
            placeholderText: "Enter name"
            placeholderTextColor: "#807B72"
            color: "black"
            width: 200
            height: 30
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
            leftPadding: 10
            background: Rectangle {
                color: customer_name1.focus ? "#B9B09D":"white"
                radius: 5
                border.color: "black"
                border.width: 1
            }
            anchors{
                top: select_room1.bottom
                topMargin: 10
                horizontalCenter: triple.horizontalCenter
            }
        }
        TextField{
            id: customer_phone1
            placeholderText: "Enter phone number"
            placeholderTextColor: "#807B72"
            color: "black"
            width: 200
            height: 30
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
            leftPadding: 10
            background: Rectangle {
                color: customer_phone1.focus ? "#B9B09D":"white"
                radius: 5
                border.color: "black"
                border.width: 1
            }
            anchors{
                top: customer_name1.bottom
                topMargin: 10
                horizontalCenter: triple.horizontalCenter
            }
        }
        Row{
            id: time_book1
            anchors{
                top: customer_phone1.bottom
                topMargin: 10
            }
            spacing: 10
            TextField{
                id: day1
                placeholderText: "Day"
                placeholderTextColor: "#807B72"
                color: "black"
                width: 60
                height: 30
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 10
                leftPadding: 10
                background: Rectangle {
                    color: day1.focus ? "#B9B09D":"white"
                    border.color: "black"
                    border.width: 1
                    radius: 5
                }
            }
            TextField{
                id: month1
                placeholderText: "Month"
                placeholderTextColor: "#807B72"
                color: "black"
                width: 60
                height: 30
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 10
                leftPadding: 10
                background: Rectangle {
                    color: month1.focus ? "#B9B09D":"white"
                    border.color: "black"
                    border.width: 1
                    radius: 5
                }
            }
            TextField{
                id: year1
                placeholderText: "Year"
                placeholderTextColor: "#807B72"
                color: "black"
                width: 60
                height: 30
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 10
                leftPadding: 10
                background: Rectangle {
                    color: year1.focus ? "#B9B09D":"white"
                    border.color: "black"
                    border.width: 1
                    radius: 5
                }
            }
        }
        Button{
            id: bt_booking1
            width: 100
            height: 25
            anchors{
                top:time_book1.bottom
                topMargin: 10
                horizontalCenter: time_book1.horizontalCenter
            }
            Text{
                text: "Book"
                color: 	"black"
                anchors.centerIn: bt_booking1
                font.pointSize: 10
            }
            background: Rectangle{
                color: bt_booking1.pressed ?"white":"#E4B14D"
                radius: 10
                border.width: 1
            }
            onClicked: {
                dbManager.Booking(booking.room1, customer_name1.text,
                                  year1.text+"-"+month1.text+"-"+day1.text,2, customer_phone1.text);
            }
        }
    }

    Text{
        id: text_vip
        text: "Vip Room"
        font.bold: true
        font.pointSize: 13
        anchors{
            top: booking.top
            left: triple.right
            leftMargin: 30
            topMargin: 55
        }
    }
    Image{
        id: vip
        width: 200
        height: 130
        anchors{
            top: text_vip.bottom
            left: triple.right
            leftMargin: 30
            topMargin: 10
        }
        source: "qrc:/image/vip.png"
    }
    Column{
        id: vip_book
        anchors{
            topMargin: 10
            top: vip.bottom
            left: triple.right
            leftMargin: 30
        }
        ComboBox{
            id: select_room2
            width: 200
            height: 30
            currentIndex: 0
            model: select_room2ListModel

            ListModel{
                id: select_room2ListModel
                ListElement{
                    key: "Select Room"
                }
                ListElement{
                    key: "107"
                }
                ListElement{
                    key: "108"
                }
                ListElement{
                    key: "207"
                }
                ListElement{
                    key: "208"
                }
                ListElement{
                    key: "307"
                }
                ListElement{
                    key: "308"
                }
                ListElement{
                    key: "407"
                }
                ListElement{
                    key: "408"
                }
            }
            contentItem: Text{
                text: select_room2.displayText
                font.pointSize: 13
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "black"
            }
            onActivated: {
                if (select_room2.currentIndex === 1) {
                    booking.room2 = 107;
                } else if (select_room2.currentIndex === 2) {
                    booking.room2 = 108;
                }else if (select_room2.currentIndex === 3) {
                    booking.room2 = 207;
                }else if (select_room2.currentIndex === 4) {
                    booking.room2 = 208;
                } else if (select_room2.currentIndex === 5) {
                    booking.room2 = 307;
                }else if (select_room2.currentIndex === 6) {
                    booking.room2 = 308;
                }  else if (select_room2.currentIndex === 7) {
                    booking.room2 = 407;
                } else if (select_room2.currentIndex === 8) {
                    booking.room2 = 408;
                }
            }
        }

        TextField{
            id: customer_name2
            placeholderText: "Enter name"
            placeholderTextColor: "#807B72"
            color: "black"
            width: 200
            height: 30
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
            leftPadding: 10
            background: Rectangle {
                color: customer_name2.focus ? "#B9B09D":"white"
                radius: 5
                border.color: "black"
                border.width: 1
            }
            anchors{
                top: select_room2.bottom
                topMargin: 10
                horizontalCenter: vip.horizontalCenter
            }
        }
        TextField{
            id: customer_phone2
            placeholderText: "Enter phone number"
            placeholderTextColor: "#807B72"
            color: "black"
            width: 200
            height: 30
            verticalAlignment: Text.AlignVCenter
            font.pointSize: 10
            leftPadding: 10
            background: Rectangle {
                color: customer_phone2.focus ? "#B9B09D":"white"
                radius: 5
                border.color: "black"
                border.width: 1
            }
            anchors{
                top: customer_name2.bottom
                topMargin: 10
                horizontalCenter: vip.horizontalCenter
            }
        }
        Row{
            id: time_book2
            anchors{
                top: customer_phone2.bottom
                topMargin: 10
            }
            spacing: 10
            TextField{
                id: day2
                placeholderText: "Day"
                placeholderTextColor: "#807B72"
                color: "black"
                width: 60
                height: 30
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 10
                leftPadding: 10
                background: Rectangle {
                    color: day2.focus ? "#B9B09D":"white"
                    border.color: "black"
                    border.width: 1
                    radius: 5
                }
            }
            TextField{
                id: month2
                placeholderText: "Month"
                placeholderTextColor: "#807B72"
                color: "black"
                width: 60
                height: 30
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 10
                leftPadding: 10
                background: Rectangle {
                    color: month2.focus ? "#B9B09D":"white"
                    border.color: "black"
                    border.width: 1
                    radius: 5
                }
            }
            TextField{
                id: year2
                placeholderText: "Year"
                placeholderTextColor: "#807B72"
                color: "black"
                width: 60
                height: 30
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 10
                leftPadding: 10
                background: Rectangle {
                    color: year2.focus ? "#B9B09D":"white"
                    border.color: "black"
                    border.width: 1
                    radius: 5
                }
            }
        }
        Button{
            id: bt_booking2
            width: 100
            height: 25
            anchors{
                top:time_book2.bottom
                topMargin: 10
                horizontalCenter: time_book2.horizontalCenter
            }
            Text{
                text: "Book"
                color: 	"black"
                anchors.centerIn: bt_booking2
                font.pointSize: 10
            }
            background: Rectangle{
                color: bt_booking2.pressed ?"white":"#E4B14D"
                radius: 10
                border.width: 1
            }
            onClicked: {
                dbManager.Booking(booking.room2, customer_name2.text,
                                  year2.text+"-"+month2.text+"-"+day2.text,3, customer_phone2.text);
            }
        }
    }
    Text{
        id: note_booking
        text:dbManager.booking
        anchors{
            bottom:booking.bottom
            bottomMargin: 20
            horizontalCenter: booking.horizontalCenter
        }
    }
}

