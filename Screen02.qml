import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 1920
    height: 1079
    title: "Application Window"
    property string currDate: "00:00:00"
    property string currTime: "00:00:00"
    property string timeServer: "00:00:00"
    property string siteLongitude: "00:00:00"
    property string siteLatitude: "00:00:00"
    property string timeZone: "00:00:00"
    property string currAz: "00:00:00"
    property string currEl: "00:00:00"

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
                text: timeServer
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: longitude
                x: 165
                y: 18
                color: "#ff0000"
                text: siteLongitude
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: latidude
                x: 150
                y: 50
                color: "#ff0000"
                text: siteLatitude
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: time_zone
                x: 165
                y: 83
                color: "#ff0000"
                text: timeZone
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
                y: 50
                text: qsTr("Sun Elevation:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: air_mass_label
                x: 31
                y: 83
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
                font.pixelSize: 26
                horizontalAlignment: Text.AlignHCenter
                font.family: "Arial"
                font.bold: true
            }

            Label {
                id: sunrise_label
                x: 870
                y: 18
                text: qsTr("Sunrise:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: solar_noon_label
                x: 870
                y: 50
                text: qsTr("Solar Noon:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Label {
                id: sunset_label
                x: 870
                y: 83
                text: qsTr("Sunset:")
                font.bold: true
                font.family: "Arial"
                font.pointSize: 18
            }

            Text {
                id: sunrise
                x: 972
                y: 18
                color: "#ff0000"
                text: "00:00:00"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: solar_noon
                x: 1012
                y: 50
                color: "#ff0000"
                text: "00:00:00"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: sunset
                x: 962
                y: 83
                color: "#ff0000"
                text: "00:00:00"
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: sun_az
                x: 192
                y: 18
                color: "#ff0000"
                text: currAz
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: sun_el
                x: 207
                y: 50
                color: "#ff0000"
                text: currEl
                font.pixelSize: 24
                font.bold: true
            }

            Text {
                id: air_mass
                x: 145
                y: 83
                color: "#ff0000"
                text: "0.00"
                font.pixelSize: 24
                font.bold: true
            }
        }
        Rectangle {
            id: automatic_stow_functions_title
            x: 0
            y: 250
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
            y: 316
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
            y: 509
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
            y: 575
            width: 1150
            height: 430
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

        Rectangle {
            id: drop_down_menu_window
            x: 1233
            y: 0
            width: 687
            height: 477
            color: "#e7e5e6"
            border.width: 5

            Image {
                id: image1
                x: 3
                y: 4
                width: 683
                height: 472
                source: "../two-axis-tracker-controller-code/images/command_window.png"
                fillMode: Image.PreserveAspectFit

                ComboBox {
                    id: drop_down_menu
                    displayText: "SELECT OPTION"
                    editable: true
                    model: ListModel {
                        id: model
                        ListElement {
                            text: "HALT"
                        }
                        ListElement {
                            text: "EMSL"
                        }
                        ListElement {
                            text: "TRACK SUN"
                        }
                        ListElement {
                            text: "HELIOSTAT"
                        }
                        ListElement {
                            text: "STOW"
                        }
                        ListElement {
                            text: "SELF-ALIGN"
                        }
                        ListElement {
                            text: "GO TO POSITION"
                        }
                        ListElement {
                            text: "HELP"
                        }
                    }
                    x: 47
                    y: 75
                    width: 365
                    height: 60
                    flat: false
                    font.bold: true
                    font.pointSize: 18
                }

                Button {
                    id: run_command_button
                    x: 47
                    y: 416
                    width: 327
                    height: 37
                    text: qsTr("Run Command")
                    flat: false
                    font.bold: true
                    icon.color: "#ff0000"
                    font.pointSize: 18
                    highlighted: true
                }

                TextInput {
                    id: command_input1
                    x: 29
                    y: 8
                    width: 634
                    height: 76
                    color: "#ffffff"
                    text: qsTr(">")
                    font.pixelSize: 18
                    font.bold: true
                }

                Rectangle {
                    id: azimuth_input_rect
                    x: 181
                    y: 263
                    width: 181
                    height: 48
                    visible: false
                    color: "#ffffff"

                    TextInput {
                        id: azimuth_input
                        x: 8
                        y: 1
                        width: 158
                        height: 48
                        visible: false
                        text: qsTr("Text Input")
                        font.pixelSize: 20
                        verticalAlignment: Text.AlignVCenter
                        font.bold: true
                    }
                }
                Rectangle {
                    id: el_input_rect
                    x: 181
                    y: 329
                    width: 181
                    height: 48
                    visible: false
                    color: "#ffffff"
                    TextInput {
                        id: el_input
                        x: 8
                        y: 1
                        width: 158
                        height: 48
                        visible: false
                        text: qsTr("Text Input")
                        font.pixelSize: 20
                        verticalAlignment: Text.AlignVCenter
                        font.bold: true
                    }
                }

                Label {
                    id: azumith_label
                    x: 41
                    y: 272
                    visible: false
                    text: qsTr("Azimuth:")
                    font.bold: true
                    font.family: "Arial"
                    font.pointSize: 20
                }

                Label {
                    id: el_input_label
                    x: 41
                    y: 338
                    visible: false
                    text: qsTr("Elevation:")
                    font.bold: true
                    font.pointSize: 20
                    font.family: "Arial"
                }
                states: State {
                    name: "Seeking Position"
                    when: (drop_down_menu.currentText == "HELIOSTAT" || drop_down_menu.currentText == "GO TO POSITION") && (drop_down_menu.currentTextChanged)

                    PropertyChanges {
                        target: el_input_rect
                        visible: true
                    }

                    PropertyChanges {
                        target: el_input
                        visible: true
                    }

                    PropertyChanges {
                        target: el_input_label
                        visible: true
                    }

                    PropertyChanges {
                        target: azimuth_input_rect
                        visible: true
                    }

                    PropertyChanges {
                        target: azimuth_input
                        visible: true
                    }

                    PropertyChanges {
                        target: azumith_label
                        visible: true
                    }
                }
            }
        }
        Rectangle {
            id: emergency_wind_stow_window
            x: 1233
            y: 474
            width: 687
            height: 69
            color: "#e6e5e5"
            border.width: 5

            Button {
                id: emercency_wind_stow
                x: 180
                y: 16
                width: 327
                height: 37
                text: qsTr("Emergency Wind Stow")
                icon.color: "#ff0000"
                highlighted: true
                font.bold: true
                font.pointSize: 18
            }
        }
        Rectangle {
            id: spacer_label
            x: 1145
            y: 510
            width: 93
            height: 500
            color: "#00afee"
            border.width: 5
        }
        Rectangle {
            id: enter_command_window
            x: 1233
            y: 539
            width: 687
            height: 69
            color: "#d53715f7"
            border.width: 5

            Text {
                id: enter_command_label
                x: 28
                y: 19
                color: "#ffffff"
                text: qsTr("Enter Command:")
                font.pixelSize: 23
                font.bold: true
            }
        }

        Rectangle {
            id: command_window
            x: 1233
            y: 604
            width: 687
            height: 111
            color: "#d53715f7"
            border.width: 5

            TextInput {
                id: command_input
                x: 29
                y: 8
                width: 634
                height: 76
                color: "#ffffff"
                text: qsTr("> ")
                font.pixelSize: 26
                font.bold: true
            }
        }

        Rectangle {
            id: error_message_label_window
            x: 1233
            y: 712
            width: 687
            height: 59
            color: "#d53715f7"
            border.width: 5
            Text {
                id: error_message_label
                x: 28
                y: 14
                color: "#ffffff"
                text: qsTr("Error Message:")
                font.pixelSize: 23
                font.bold: true
            }
        }

        Rectangle {
            id: error_message_window
            x: 1233
            y: 767
            width: 687
            height: 104
            color: "#d53715f7"
            border.width: 5

            Text {
                id: error_message
                x: 25
                y: 8
                color: "#ddf634"
                text: qsTr("ERROR: Command Cannot Be Executed")
                font.pixelSize: 23
                font.bold: true
            }
        }
        Rectangle {
            id: batch_file_window
            x: 1233
            y: 868
            width: 687
            height: 140
            color: "#e6e5e5"
            border.width: 5
            Button {
                id: upload_batch_file
                x: 77
                y: 45
                width: 250
                height: 37
                text: qsTr("Upload Batch File")
                font.pointSize: 18
                highlighted: true
                font.bold: true
                icon.color: "#ff0000"
            }

            Button {
                id: upload_batch_file1
                x: 404
                y: 45
                width: 191
                height: 37
                text: qsTr("Run Batch File")
                font.pointSize: 18
                highlighted: true
                icon.color: "#ff0000"
                font.bold: true
            }

            Text {
                id: file_upload
                x: 77
                y: 85
                width: 120
                height: 22
                text: qsTr("Uploaded: ")
                font.pixelSize: 16
            }
        }
    }
    
}