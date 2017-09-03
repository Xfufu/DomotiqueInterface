/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Window 2.2

ApplicationWindow {
    visible: true
    width: Screen.width
    height: Screen.height
    title: qsTr("Hello World")
    background: Rectangle {
        gradient: Gradient {
            GradientStop {
                position: 0.00;
                color: "#82BA27";
            }
            GradientStop {
                position: 1.00;
                color: "#ffffff";
            }
        }
    }
    ObjectDisplay{
        anchors.fill: parent
    }
}
