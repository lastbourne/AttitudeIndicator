import QtQuick 2.15
import QtQuick.Window 2.12

Window {
    id:window
    visible: true
    color: "grey"
    width: 400
    height: 400

    property real attitude: 0
    property real roll: 0

    Rectangle {
        id: root

        anchors.fill: parent
        anchors.margins: 25
        color: "black"
        radius: 25

        Rectangle {
            id: border

            anchors.fill: parent
            anchors.margins: 25
            z: 1

            color: "grey"
            border.width: 25
            border.color: "black"
            clip: true

            Rectangle {
                id: filler
                color: "grey"

                width: 1600
                height: 1600

                anchors.centerIn: parent
                anchors.margins: 25
                radius: 25

                anchors.verticalCenterOffset: window.attitude

                Rectangle {
                    id: sky
                    color: "lightblue"

                    anchors {top: parent.top; left: parent.left; right: parent.right; bottom: parent.verticalCenter}
                }

                Rectangle {
                    id: earth
                    color: "#4d2800"

                    anchors {top: parent.verticalCenter; left: parent.left; right: parent.right; bottom: parent.bottom}

                }              

                rotation: window.roll

            }

            Rectangle {
                id: plane_position
                color: "white"

                width: 200
                height: 4
                radius: 4

                anchors.centerIn: parent
            }

        }
    }
}
