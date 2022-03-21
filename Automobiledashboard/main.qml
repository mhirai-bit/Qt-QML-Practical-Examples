import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Extras 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 1.4

Window {
    id: window
    width: 1000
    height: 1000
    visible: true
    title: qsTr("Automobile Dashboard")

    Column {
        id: leftPanel
        anchors.left: parent.left
        anchors.top: parent. top
        width: parent.width * 0.2
        spacing: 20

        Button {
            id: confButton
            text: "Vechile Configuration"
            onClicked: {
                centralPanelLoader.source = "VehicleConfiguration.qml"
            }
        }
        Button {
            id: simButton
            text: "Dashboard Simulation"
            onClicked: {
                centralPanelLoader.source = "DashboardSimulator.qml"
            }
        }
    }

    Loader {
        id: centralPanelLoader
        anchors.centerIn: parent
        width: parent.width
    }
}
