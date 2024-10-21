import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Rectangle {
    id: calendar_id
    visible: true
    width: 280
    height: 150
    property string data_day:""
    property var daysOfWeek: ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]
    property int currentYear: new Date().getFullYear()
    property int currentMonth: new Date().getMonth()
    property int daysInMonth: new Date(currentYear, currentMonth + 1, 0).getDate()
    property int firstDayOfMonth: new Date(currentYear, currentMonth, 1).getDay()
    property int check: -1
    ColumnLayout {
        anchors.fill: calendar_id
        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            Button {
                text: "<"
                onClicked: {
                    currentMonth = (currentMonth - 1 + 12) % 12
                    if (currentMonth === 11) {
                        currentYear--
                    }
                    updateCalendar()
                }
            }
            Text {
                text: Qt.formatDate(new Date(currentYear, currentMonth), "MMMM yyyy")
                font.pixelSize: 20
                Layout.alignment: Qt.AlignHCenter
            }
            Button {
                text: ">"
                onClicked: {
                    currentMonth = (currentMonth + 1) % 12
                    if (currentMonth === 0) {
                        currentYear++
                    }
                    updateCalendar()
                }
            }
        }

        RowLayout {
            spacing: 21
            Repeater {
                model: daysOfWeek
                Text {
                    text: modelData
                    width: calendar_id.width / 7
                    horizontalAlignment: Text.AlignHCenter
                    font.bold: true
                    font.pointSize: 10
                }
            }
        }

        GridLayout {
            columns: 7
            Repeater {
                model: 42 // 6 weeks * 7 days
                Rectangle {
                    id: box
                    width: calendar_id.width / 7
                    height: 40
                    border.color: "black"
                    color: index===calendar_id.check? "#E4B14D":(index >= firstDayOfMonth && index < firstDayOfMonth + daysInMonth ? "white" : "#E4B14D")
                    radius: 10
                    Text {
                        text: index >= firstDayOfMonth && index < firstDayOfMonth + daysInMonth ? (index - firstDayOfMonth + 1).toString() : ""
                        anchors.centerIn: parent
                        font.pointSize: 11
                        font.bold: true
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            if (index >= firstDayOfMonth && index < firstDayOfMonth + daysInMonth) {
                                var selectedDay = index - firstDayOfMonth + 1
                                calendar_id.data_day = currentYear + "-" + (currentMonth + 1) + "-" + selectedDay;

                                calendar_id.check = index
                            }
                        }
                    }
                }
            }
        }
    }

    function updateCalendar() {
        daysInMonth = new Date(currentYear, currentMonth + 1, 0).getDate()
        firstDayOfMonth = new Date(currentYear, currentMonth, 1).getDay()
    }
}
