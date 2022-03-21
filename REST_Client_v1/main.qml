import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Controls 1.4

ApplicationWindow {
    id: rootwindow
    width: 1200
    height: 1000
    visible: true
    title: qsTr("REST Client")

    property var selDate: ""

    Column {
        anchors.fill: parent
        anchors.leftMargin: 10
        spacing: 10
        Row{
            spacing: 10
            Button {
                id: buttonid
                text: "Get APOD"
                onClicked: {
                    // send get request
                    restClient.createGetRequest("https://api.nasa.gov/planetary/apod?api_key=DEMO_KEY" + "&date=" + selDate);
                }
            }
            Button {
                id: dateselector
                text: "Select Date"
                onClicked: {
                    calDialog.visible = true
                }
            }
            Text {
                anchors.verticalCenter: parent.verticalCenter
                text: selDate
                font.pointSize: 10
            }
        }

        Text {
            text: "Response"
            font.pointSize: 10
        }
        Rectangle {
            width: rootwindow.width * 0.6
            height: rootwindow.height * 0.2
            border.color: "green"

            ScrollView {
                anchors.fill: parent
                TextArea {
                    id: responsetext
                    text: restClient.responseText
                    font.pointSize: 10
                    wrapMode: TextEdit.WordWrap
                }
            }
        }
        Text {
            text: "Image"
            font.pointSize: 10
        }
        Rectangle {
            width: rootwindow.width * 0.6
            height: rootwindow.height * 0.4
            border.color: "black"
            Image {
                anchors.fill: parent
                source: restClient.imageUrl
            }
        }
    }
    Calendar {
        id: calDialog
        visible: false
        anchors.top: parent.top
        anchors.topMargin: 40
        onSelectedDateChanged: {
            var locale = Qt.locale()
            selDate = selectedDate.toLocaleDateString(locale, "yyyy-MM-dd")
            visible = false
        }
//        onFocusChanged: {
//            if(focus == true)
//            {
//                visible = true
//            }
//            else
//            {
//                visible = false;
//            }
//        }
    }
}
