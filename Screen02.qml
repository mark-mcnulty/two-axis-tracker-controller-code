import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 1920
    height: 1079
    title: "Application Window"
    property string currDate: "00:00:00"
    property string currTime: "00:00:00"

    Rectangle {
        id: application_window
        visible: true
        width: parent.width
        height: parent.height

        color: "#00afee"
        border.width: 0

        Rectangle {
            id: title_block
            x: 0
            y: 0
            width: 1237
            height: 130
            color: "#00afee"
            border.width: 5

            Label {
                id: longitude_label
                x: 31
                y: 18
                text: qsTr("Longitude:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: latitude_label
                x: 31
                y: 50
                text: qsTr("Latidude:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: time_zone_label
                x: 31
                y: 83
                text: qsTr("Time Zone:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Text {
                id: title
                anchors.centerIn: parent
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
                y: 18
                text: qsTr("Date:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: local_time_label
                x: 870
                y: 50
                text: qsTr("Local Time:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: time_server_label
                x: 870
                y: 83
                text: qsTr("Time Server:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Text {
                id: curr_date
                x: 940
                y: 18
                text: currDate
                color: "#ff0000"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: curr_time
                x: 1010
                y: 50
                color: "#ff0000"
                text: currTime
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: time_server
                x: 1020
                y: 83
                color: "#ff0000"
                text: "time.server"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: longitude
                x: 190
                y: 18
                color: "#ff0000"
                text: "000.000"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: latidude
                x: 168
                y: 50
                color: "#ff0000"
                text: "00.00"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: time_zone
                x: 195
                y: 83
                color: "#ff0000"
                text: "7"
                font.pixelSize: 24
                font.bold: true
            }
        }
        Rectangle {
            id: sun_air_parameters
            x: 0
            y: 125
            width: 1237
            height: 130
            color: "#00afee"
            border.width: 5
            Label {
                id: sun_az_label
                x: 31
                y: 18
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
                anchors.centerIn: parent
                width: 382
                height: 84
                text: qsTr("Sun/Air \nParameters:")
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
        Rectangle {
            id: automatic_stow_functions_title
            x: 0
            y: 329
            width: 1237
            height: 71
            color: "#00afee"
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
            color: "#00afee"
            border.width: 5

            Image {
                id: label
                x: 5
                y: -2
                width: 1230
                height: 206
                source: "../two-axis-tracker-controller-code/images/Automatic-Stow-Functions.jpg"
                fillMode: Image.PreserveAspectFit

                Text {
                    id: wind_port
                    x: 328
                    y: 61
                    color: "#ff0000"
                    text: "00.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: temp_port
                    x: 328
                    y: 109
                    color: "#ff0000"
                    text: "00.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: aux_port
                    x: 328
                    y: 155
                    color: "#ff0000"
                    text: "00.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: wind_status
                    x: 583
                    y: 61
                    color: "#ff0000"
                    text: "00.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: temp_status
                    x: 583
                    y: 109
                    color: "#ff0000"
                    text: "00.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: aux_status
                    x: 583
                    y: 155
                    color: "#ff0000"
                    text: "00.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: wind_stow_delay
                    x: 831
                    y: 61
                    color: "#ff0000"
                    text: "00.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: temp_stow_delay
                    x: 831
                    y: 109
                    color: "#ff0000"
                    text: "00.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: aux_stow_delay
                    x: 831
                    y: 155
                    color: "#ff0000"
                    text: "00.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: wind_rec_delay
                    x: 1076
                    y: 61
                    color: "#ff0000"
                    text: "00.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: temp_rec_delay
                    x: 1076
                    y: 109
                    color: "#ff0000"
                    text: "00.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: aux_rec_delay
                    x: 1076
                    y: 155
                    color: "#ff0000"
                    text: "00.00"
                    font.pixelSize: 24
                    font.bold: true
                }
            }
        }

         Rectangle {
            id: tracker_status_label
            x: 0
            y: 586
            width: 1150
            height: 71
            color: "#00afee"
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
            width: 1150
            height: 428
            color: "#00afee"
            border.width: 5

            Image {
                id: tracker_status_image
                x: -457
                y: 2
                width: 2065
                height: 420
                source: "../two-axis-tracker-controller-code/images/Tracker-Status.jpg"
                fillMode: Image.PreserveAspectFit
                

                Text {
                    id: curr_status
                    x: 1179
                    y: 8
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: azimuth_label
                    x: 984
                    y: 54
                    color: "#ff0000"
                    text: "Azimuth"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: com_position_az
                    x: 995
                    y: 103
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: act_position_az
                    x: 994
                    y: 149
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: pos_error_az
                    x: 995
                    y: 194
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: offset_az
                    x: 994
                    y: 240
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: elevation_label
                    x: 1356
                    y: 54
                    color: "#ff0000"
                    text: "Elevation"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: com_position_el
                    x: 1369
                    y: 100
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: act_position_el
                    x: 1368
                    y: 149
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: pos_error_el
                    x: 1369
                    y: 194
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: offset_el
                    x: 1368
                    y: 240
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: min_update
                    x: 1177
                    y: 288
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: motor_status_az
                    x: 995
                    y: 334
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: motor_status_el
                    x: 1370
                    y: 334
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: limit_switch_status_ea_az
                    x: 891
                    y: 380
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: limit_switch_status_dn_az
                    x: 1082
                    y: 380
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: limit_switch_status_ea_el
                    x: 1285
                    y: 380
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }

                Text {
                    id: limit_switch_status_dn_el
                    x: 1476
                    y: 380
                    color: "#ff0000"
                    text: "000.00"
                    font.pixelSize: 24
                    font.bold: true
                }
            }
        }
    }

}