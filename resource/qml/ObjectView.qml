/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

import QtQuick 2.0

Item {
    id: objectView
    anchors.fill: parent
    property string name: ""
    property var modelList
    Text {
        id: nameText
        anchors.top: parent.top
        width: parent.width
        height: contentHeight
        text: name
        fontSizeMode: Text.Fit
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    GridView {
        anchors.top: nameText.bottom
        width: parent.width
        anchors.bottom: parent.bottom
        model: modelList
        delegate: Text {
            text: diid
            height: contentHeight
            width: contentWidth
        }
        onCountChanged: console.log("count changed")
    }
}
