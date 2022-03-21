import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtQuick.Layouts 1.12
import QtQuick.Dialogs 1.2
import Qt.labs.platform 1.0
import notepad.example.texteditor 1.0

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: "Notepad - " + docController.curFileName

    Shortcut {
        sequence: StandardKey.Open
        onActivated: openFileDialog.open()
    }
    Shortcut {
        sequence: StandardKey.SaveAs
        onActivated: saveFileDialog.open()
    }
    Shortcut {
        sequence: StandardKey.Quit
        onActivated: close()
    }

    MenuBar {
        id: notePadMenu
        Menu {
            id: fileMenu
            title: qsTr("File")
            MenuItem {
                text: qsTr("New")
                enabled: true
                onTriggered: {
                    // call function to open file
                    newFile.open()
                }
            }
            MenuItem {
                text: qsTr("Open")
                enabled: true
                onTriggered: openFileDialog.open()
            }
            MenuItem {
                text: qsTr("Save")
                enabled: true
                onTriggered: {
                    if(!docController.saveContent())
                    {
                        saveDialog.open();
                    }
                }
            }
            MenuItem {
                text: qsTr("Save as")
                enabled: true
                onTriggered: saveFileDialog.open()
            }
            MenuItem {
                text: qsTr("Print")
                enabled: true
            }
            MenuItem {
                text: qsTr("Exit")
                enabled: true
                onTriggered: close()
            }
        }
        Menu {
            id: editMenu
            title: qsTr("Edit")
            MenuItem {
                text: qsTr("Undo")
                enabled: true
            }
            MenuItem {
                text: qsTr("Cut")
                enabled: true
                onTriggered: textEditArea.cut()
            }
            MenuItem {
                text: qsTr("Copy")
                enabled: true
                onTriggered: textEditArea.copy()
            }
            MenuItem {
                text: qsTr("Paste")
                enabled: true
                onTriggered: textEditArea.paste()
            }
            MenuItem {
                text: qsTr("Select All")
                enabled: true
                onTriggered: textEditArea.selectAll()
            }
        }
        Menu {
            id: formatMenu
            title: qsTr("Format")
            MenuItem {
                text: qsTr("Font")
                enabled: true
                onTriggered:
                {
                    fontDialog.currentFont.pointSize = docController.fontSize
                    fontDialog.currentFont.family = docController.fontFamily
                    fontDialog.open()
                }
            }
            MenuItem {
                text: qsTr("Word Wrap")
                enabled: true
            }
        }
        Menu {
            id: viewMenu
            title: qsTr("View")
            MenuItem {
                text: qsTr("Status Bar")
                enabled: true
                checkable: true
            }
        }
        Menu {
            id: helpMenu
            title: qsTr("Help")
            MenuItem {
                text: qsTr("Help")
                enabled: true
            }
            MenuItem {
                text: qsTr("About Notepad")
                enabled: true
            }
        }
    }

    header: ToolBar {
        id: topToolbar
        Row {
            anchors.fill: parent
            ToolButton {
                id: newButton
                contentItem:  Rectangle {
                    color: "black"
                    Image {
                        anchors.fill: parent
                        source: "images/Newfile.svg"
                    }
                }
                onClicked: newFile.open()
            }
            ToolButton {
                id: openButton
                contentItem:  Rectangle {
                    color: "black"
                    Image {
                        anchors.fill: parent
                        source: "images/folder-open.svg"
                    }
                }
                onClicked: openFileDialog.open()
            }
            ToolButton {
                id: saveButton
                contentItem:  Rectangle {
                    color: "black"
                    Image {
                        anchors.fill: parent
                        source: "images/save.svg"
                    }
                }
                onClicked: {
                    if(docController.saveContent())
                    {
                        saveDialog.open()
                    }

                }
            }
            ToolButton {
                id: saveAsButton
                contentItem:  Rectangle {
                    color: "black"
                    Image {
                        anchors.fill: parent
                        source: "images/saveas.svg"
                    }
                }
                onClicked: saveFileDialog.open()
            }
            ToolButton {
                id: printButton
                contentItem:  Rectangle {
                    color: "black"
                    Image {
                        anchors.fill: parent
                        source: "images/print.svg"
                    }
                }
                onClicked: docController.printFile();
            }
            ToolButton {
                id: undoButton
                checkable: true
                checked: docController.isUndoAvailable
                contentItem:  Rectangle {
                    color: docController.isUndoAvailable ? "black" : "gray"
                    Image {
                        anchors.fill: parent
                        source: "images/undo.svg"
                    }
                }
                onClicked: docController.executeUndoRedo(true)
            }
            ToolButton {
                id: redoButton
                checkable: true
                checked: docController.isRedoAvailable
                contentItem:  Rectangle {
                    color: docController.isRedoAvailable ? "black" : "gray"
                    Image {
                        anchors.fill: parent
                        source: "images/dustin-w-Redo-icon.svg"
                    }
                }
                onClicked: docController.executeUndoRedo(false)
            }
            ToolButton {
                id: cutButton
                contentItem:  Rectangle {
                    //                    color: "black"
                    Image {
                        anchors.fill: parent
                        source: "images/cut.svg"
                    }
                }
                onClicked: textEditArea.cut()
            }
            ToolButton {
                id: copyButton
                contentItem:  Rectangle {
                    //                    color: "black"
                    Image {
                        anchors.fill: parent
                        source: "images/primary-copy.svg"
                    }
                }
                onClicked: textEditArea.copy()
            }
            ToolButton {
                id: pasteButton
                contentItem:  Rectangle {
                    //                    color: "black"
                    Image {
                        anchors.fill: parent
                        source: "images/Paste.svg"
                    }
                }
                onClicked: textEditArea.paste()
            }
            ToolButton {
                id: boldButton
                checkable: true
                checked: docController.bold
                contentItem:  Rectangle {
                    //                    color: "black"
                    Image {
                        anchors.fill: parent
                        source: "images/fttext-bold.svg"
                    }
                }
                onClicked: docController.bold = !docController.bold
            }
            ToolButton {
                id: italicButton
                checkable: true
                checked: docController.italic
                contentItem:  Rectangle {
                    //                    color: "black"
                    Image {
                        anchors.fill: parent
                        source: "images/primary-text-italic.svg"
                    }
                }
                onClicked: docController.italic = !docController.italic
            }
            ToolButton {
                id: underlineButton
                checkable: true
                checked: docController.underline
                contentItem:  Rectangle {
                    //                    color: "black"
                    Image {
                        anchors.fill: parent
                        source: "images/mono-text-under.svg"
                    }
                }
                onClicked: docController.underline = !docController.underline
            }
            ToolButton {
                id: textColor
                contentItem:  Rectangle {
                    //                    color: "black"
                    Text {
                        id: colText
                        color: colorDialog.color
                        text: "A"
                        anchors.top: parent.top
                        font.pointSize: 10
                        height: parent.height *0.8
                    }
                    Rectangle {
                        id: colorStrip
                        anchors.top: colText.bottom
                        width: parent.width
                        height: parent.height * 0.2
                        color: colorDialog.color
                    }
                }
                onClicked: colorDialog.open()
            }
            ToolButton {
                id: textAlignLeft
                checkable: true
                checked: docController.textAlignment === Qt.AlignLeft
                contentItem:  Rectangle {
                    color: "gray"
                    Image {
                        anchors.fill: parent
                        source: "images/mono-align-left.svg"
                    }
                }
                onClicked: docController.textAlignment = Qt.AlignLeft
            }
            ToolButton {
                id: textAlignCenter
                checkable: true
                checked: docController.textAlignment === Qt.AlignCenter
                contentItem:  Rectangle {
                    color: "gray"
                    Image {
                        anchors.fill: parent
                        source: "images/mono-text-center.svg"
                    }
                }
                onClicked: docController.textAlignment = Qt.AlignCenter
            }
            ToolButton {
                id: textAlignRight
                checkable: true
                checked: docController.textAlignment === Qt.AlignRight
                contentItem:  Rectangle {
                    color: "gray"
                    Image {
                        anchors.fill: parent
                        source: "images/mono-text-right.svg"
                    }
                }
                onClicked: docController.textAlignment = Qt.AlignRight
            }
        }
    }

    FontDialog {
        id: fontDialog
        onAccepted: {
            docController.fontSize = font.pointSize
            docController.fontFamily = font.family
        }
    }

    ColorDialog {
        id: colorDialog
        currentColor: "black"
    }

    FileDialog {
        id: openFileDialog
        nameFilters: ["Text & HTML (*.txt *.html *.htm)", "Text files (*.txt)", "HTML files (*.html *.htm)"]
        fileMode: FileDialog.OpenFile
        onAccepted: {
            // load file
            docController.openFile(file)
        }
        onRejected: {
            // skip open
        }
    }
    FileDialog {
        id: saveFileDialog
        nameFilters: ["Text & HTML (*.txt *.html *.htm)", "Text files (*.txt)", "HTML files (*.html *.htm)"]
        fileMode: FileDialog.SaveFile
        onAccepted: {
            // save file
            docController.saveAs(file);
        }
        onRejected: {
            // skip saving file
        }
    }
    FileDialog {
        id: newFile
        fileMode: FileDialog.SaveFile
        title: "Create new file"
        onAccepted: {
            docController.createFile(file)
        }
        onRejected: {
            // skip saving file
        }
    }

    DocumentController {
        id: docController
        notepadDoc: textEditArea.textDocument
        cursorPosition: textEditArea.cursorPosition
        selectionStart: textEditArea.selectionStart
        selectionEnd: textEditArea.selectionEnd
        textColor: colorDialog.color
        onFileContentLoaded: {
            textEditArea.textFormat = format
            textEditArea.text = content
        }
    }

    TextArea {
        id: textEditArea
        width: parent.width
        anchors.top: topToolbar.bottom
        anchors.bottom: parent.bottom
        textFormat: Qt.RichText
        selectByMouse: true
        persistentSelection: true
        Component.onCompleted: {
            forceActiveFocus
        }
    }

    footer: ToolBar {
        id: bottomToolbar
    }

}
