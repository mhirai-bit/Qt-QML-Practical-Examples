import QtQuick 2.0
import QtQml.Models 2.14

QtObject {
    id: indicatorModel


    property ListModel leftIcons : ListModel {
        id: leftBottomIndicators
        ListElement {
            name: "windowDefrost"
            src: "images/defrost.svg"
            isvisible: false
        }
        ListElement {
            name: "acin"
            src: "images/acin.svg"
            isvisible: false
        }
        ListElement {
            name: "wiper"
            src: "images/wiper.svg"
            isvisible: false
        }
    }

    property ListModel rightIcons : ListModel {
        id: rightBottomIndicators

        ListElement {
            name: "battery"
            src: "images/battery.svg"
            isvisible: false
        }
        ListElement {
            name: "gasoline"
            src: "images/gasoline.svg"
            isvisible: false
        }
        ListElement {
            name: "settings"
            src: "images/settings.svg"
            isvisible: false
        }
        ListElement {
            name: "enginefault"
            src: "images/enginefault.svg"
            isvisible: false
        }
    }

    function getIconVisibility(name)
    {
        for(var i = 0; i < leftIcons.count; i++)
        {
            if(leftIcons.get(i).name === name)
            {
                return leftIcons.get(i).isvisible
            }
        }
        for(var j = 0; j < rightIcons.count; j++)
        {
            if(rightIcons.get(j).name === name)
            {
                return rightIcons.get(j).isvisible
            }
        }
    }

    function setIconVisibility(name, value)
    {
        for(var i = 0; i < leftIcons.count; i++)
        {
            if(leftIcons.get(i).name === name)
            {
                leftIcons.setProperty(i, "isvisible", value)
                return
            }
        }
        for(var j = 0; j < rightIcons.count; j++)
        {
            if(rightIcons.get(j).name === name)
            {
                rightIcons.setProperty(j, "isvisible", value)
                return
            }
        }
    }
}
