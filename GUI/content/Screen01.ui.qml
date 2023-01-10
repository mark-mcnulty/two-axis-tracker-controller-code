

/*
This is a UI file (.ui.qml) that is intended to be edited in Qt Design Studio only.
It is supposed to be strictly declarative and only uses a subset of QML. If you edit
this file manually, you might introduce QML code that is not supported by Qt Design Studio.
Check out https://doc.qt.io/qtcreator/creator-quick-ui-forms.html for details on .ui.qml files.
*/
import QtQuick 6.2
import QtQuick.Controls 6.2
import GUI

Rectangle {
    id: application_window
    visible: true
    width: Constants.width
    height: Constants.height

    color: Constants.backgroundColor
    border.width: 1

    property string currDate: "00/00/00"

    Rectangle {
        id: title_block
        x: 0
        y: 0
        width: 1237
        height: 165
        color: "#00cdff"
        border.width: 5

        Label {
            id: longitude_label
            x: 31
            y: 30
            text: qsTr("Longitude:")
            font.bold: true
            font.family: "Arial"
            font.pointSize: 20
        }

        Label {
            id: latitude_label
            x: 29
            y: 67
            text: qsTr("Latidude:")
            font.bold: true
            font.family: "Arial"
            font.pointSize: 20
        }

        Label {
            id: latitude_label1
            x: 31
            y: 101
            text: qsTr("Time Zone:")
            font.bold: true
            font.family: "Arial"
            font.pointSize: 20
        }

        Text {
            id: title
            x: 393
            y: 48
            width: 382
            height: 84
            text: qsTr("Solar Array Tracker\nNREL Site")
            font.pixelSize: 30
            horizontalAlignment: Text.AlignHCenter
            font.weight: Font.ExtraBold
            font.family: "Arial"
            font.bold: true
        }

        Label {
            id: date_label
            x: 920
            y: 30
            text: qsTr("Date:")
            font.bold: true
            font.family: "Arial"
            font.pointSize: 20
        }

        Label {
            id: local_time_label
            x: 920
            y: 67
            text: qsTr("Local Time:")
            font.bold: true
            font.family: "Arial"
            font.pointSize: 20
        }

        Label {
            id: time_server_label
            x: 920
            y: 101
            text: qsTr("Time Server:")
            font.bold: true
            font.family: "Arial"
            font.pointSize: 20
        }

        Text {
            id: curr_date
            x: 1003
            y: 30
            text: currDate
            color: "#ff0000"
            font.pixelSize: 24
            font.bold: true
        }

        Text {
            id: curr_time
            x: 1076
            y: 68
            color: "#ff0000"
            text: "00:00:00"
            font.pixelSize: 24
            font.bold: true
        }

        Text {
            id: time_server
            x: 1095
            y: 101
            color: "#ff0000"
            text: "time.server"
            font.pixelSize: 24
            font.bold: true
        }

        Text {
            id: longitude
            x: 176
            y: 30
            color: "#ff0000"
            text: "000.000"
            font.pixelSize: 24
            font.bold: true
        }

        Text {
            id: latidude
            x: 156
            y: 67
            color: "#ff0000"
            text: "00.00"
            font.pixelSize: 24
            font.bold: true
        }

        Text {
            id: time_zone
            x: 180
            y: 101
            color: "#ff0000"
            text: "7"
            font.pixelSize: 24
            font.bold: true
        }
    }

    Rectangle {
        id: sun_air_parameters
        x: 0
        y: 159
        width: 1237
        height: 175
        color: "#00cdff"
        border.width: 5
        Label {
            id: sun_az_label
            x: 31
            y: 51
            text: qsTr("Sun Azimuth:")
            font.bold: true
            font.family: "Arial"
            font.pointSize: 20
        }

        Label {
            id: sun_el_label
            x: 31
            y: 90
            text: qsTr("Sun Elevation:")
            font.bold: true
            font.family: "Arial"
            font.pointSize: 20
        }

        Label {
            id: air_mass_label
            x: 31
            y: 128
            text: qsTr("Air Mass:")
            font.bold: true
            font.family: "Arial"
            font.pointSize: 20
        }

        Text {
            id: sun_air_title
            x: 408
            y: 19
            width: 382
            height: 84
            text: qsTr("Sun/Air Parameters:")
            font.pixelSize: 26
            horizontalAlignment: Text.AlignHCenter
            font.family: "Arial"
            font.bold: true
        }

        Label {
            id: sunrise_label
            x: 923
            y: 51
            text: qsTr("Sunrise:")
            font.bold: true
            font.family: "Arial"
            font.pointSize: 20
        }

        Label {
            id: solar_noon_label
            x: 923
            y: 90
            text: qsTr("Solar Noon:")
            font.bold: true
            font.family: "Arial"
            font.pointSize: 20
        }

        Label {
            id: sunset_label
            x: 923
            y: 128
            text: qsTr("Sunset:")
            font.bold: true
            font.family: "Arial"
            font.pointSize: 20
        }

        Text {
            id: sunrise
            x: 1040
            y: 50
            color: "#ff0000"
            text: "00:00:00"
            font.pixelSize: 24
            font.bold: true
        }

        Text {
            id: solar_noon
            x: 1084
            y: 87
            color: "#ff0000"
            text: "00:00:00"
            font.pixelSize: 24
            font.bold: true
        }

        Text {
            id: sunset
            x: 1028
            y: 127
            color: "#ff0000"
            text: "00:00:00"
            font.pixelSize: 24
            font.bold: true
        }

        Text {
            id: sun_az
            x: 210
            y: 50
            color: "#ff0000"
            text: "000.00"
            font.pixelSize: 24
            font.bold: true
        }

        Text {
            id: sun_el
            x: 223
            y: 91
            color: "#ff0000"
            text: "00.00"
            font.pixelSize: 24
            font.bold: true
        }

        Text {
            id: air_mass
            x: 159
            y: 127
            color: "#ff0000"
            text: "0.00"
            font.pixelSize: 24
            font.bold: true
        }
    }

    Rectangle {
        id: automatic_stow_functions_title
        x: 0
        y: 329
        width: 1237
        height: 71
        color: "#00cdff"
        border.width: 5

        Text {
            id: auto_stow_fcns_label
            x: 408
            y: 19
            width: 382
            height: 36
            text: qsTr("Automatic Stow Functions:")
            font.pixelSize: 26
            horizontalAlignment: Text.AlignHCenter
            font.family: "Arial"
            font.bold: true
        }
    }

    Rectangle {
        id: automatic_stow_functions
        x: 0
        y: 393
        width: 1237
        height: 197
        color: "#00cdff"
        border.width: 5
    }

    Rectangle {
        id: tracker_status_label
        x: 0
        y: 586
        width: 1237
        height: 71
        color: "#00cdff"
        border.width: 5
        Text {
            id: tracker_status_label_1
            x: 408
            y: 19
            width: 382
            height: 36
            text: qsTr("Tracker Status:")
            font.pixelSize: 26
            horizontalAlignment: Text.AlignHCenter
            font.family: "Arial"
            font.bold: true
        }
    }

    Rectangle {
        id: tracker_status
        x: 0
        y: 652
        width: 1237
        height: 428
        color: "#00cdff"
        border.width: 5
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.5;height:1080;width:1920}D{i:10}D{i:11}D{i:12}D{i:13}D{i:14}
D{i:15}D{i:29}D{i:31}D{i:32}D{i:34}
}
##^##*/

