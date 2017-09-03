/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <david.lapiere@gmail.com> wrote this file. As long as you retain this notice you
 * can do whatever you want with this stuff. If we meet some day, and you think
 * this stuff is worth it, you can buy me a beer in return Poul-Henning Kamp
 * ----------------------------------------------------------------------------
 */

import QtQuick 2.7
import QtQuick.Controls 2.2

Item {
    id: objectDisplay
    SwipeView {
        id: objectSwipeView
        anchors.fill: parent
        Repeater {
            model: objectList
            delegate: ObjectView {
                id: objectViewDelegate
                anchors.fill: objectSwipeView
                name: diName
                modelList: dimodelList
            }
        }

    }
    PageIndicator {
        count: objectSwipeView.count
        currentIndex: objectSwipeView.currentIndex
    }
}
