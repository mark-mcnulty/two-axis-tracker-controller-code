import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 1900
    height: 1040
    title: "Application Window"
    property string currDate: "00:00:00"
    property string currTime: "00:00:00"

    Rectangle {
        id: application_window
        visible: true
        width: 1920
        height: 1080

        color: "#00afee"
        border.width: 1

        Rectangle {
            id: title_block
            x: 0
            y: 0
            width: 1237
            height: 165
            color: "#00afee"
            border.width: 5

            Label {
                id: longitude_label
                x: 31
                y: 30
                text: qsTr("Longitude:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: latitude_label
                x: 29
                y: 67
                text: qsTr("Latidude:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: time_zone_label
                x: 29
                y: 101
                text: qsTr("Time Zone:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
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
                x: 870
                y: 30
                text: qsTr("Date:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: local_time_label
                x: 870
                y: 67
                text: qsTr("Local Time:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: time_server_label
                x: 870
                y: 101
                text: qsTr("Time Server:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Text {
                id: curr_date
                x: 953
                y: 33
                text: currDate
                color: "#ff0000"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: curr_time
                x: 1040
                y: 69
                color: "#ff0000"
                text: currTime
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: time_server
                x: 1060
                y: 104
                color: "#ff0000"
                text: "time.server"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: longitude
                x: 190
                y: 34
                color: "#ff0000"
                text: "000.000"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: latidude
                x: 168
                y: 70
                color: "#ff0000"
                text: "00.00"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: time_zone
                x: 195
                y: 104
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
            color: "#00afee"
            border.width: 5
            Label {
                id: sun_az_label
                x: 31
                y: 51
                text: qsTr("Sun Azimuth:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: sun_el_label
                x: 31
                y: 90
                text: qsTr("Sun Elevation:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: air_mass_label
                x: 31
                y: 128
                text: qsTr("Air Mass:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Text {
                id: sun_air_title
                x: 408
                y: 19
                width: 382
                height: 84
                text: qsTr("Sun/Air Parameters:")
                font.pixelSize: 30
                horizontalAlignment: Text.AlignHCenter
                font.family: "Arial"
                font.bold: true
            }

            Label {
                id: sunrise_label
                x: 870
                y: 51
                text: qsTr("Sunrise:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: solar_noon_label
                x: 870
                y: 90
                text: qsTr("Solar Noon:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: sunset_label
                x: 870
                y: 128
                text: qsTr("Sunset:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Text {
                id: sunrise
                x: 995
                y: 54
                color: "#ff0000"
                text: "00:00:00"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: solar_noon
                x: 1043
                y: 93
                color: "#ff0000"
                text: "00:00:00"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: sunset
                x: 985
                y: 132
                color: "#ff0000"
                text: "00:00:00"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: sun_az
                x: 227
                y: 55
                color: "#ff0000"
                text: "000.00"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: sun_el
                x: 242
                y: 94
                color: "#ff0000"
                text: "00.00"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: air_mass
                x: 175
                y: 133
                color: "#ff0000"
                text: "0.00"
                font.pixelSize: 24
                font.bold: true
            }
        }

    }

}