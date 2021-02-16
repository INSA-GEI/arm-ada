#!/bin/sh

pyuic5 -o main_window_ui.py ui/main_window.ui
pyuic5 -o dialog_potentiometers_ui.py ui/dialog_potentiometers.ui
pyuic5 -o dialog_accelerometer_ui.py ui/dialog_accelerometer.ui
pyuic5 -o dialog_gyroscope_ui.py ui/dialog_gyroscope.ui
pyuic5 -o dialog_magnetometer_ui.py ui/dialog_magnetometer.ui

pyrcc5 -o ressources_rc.py ui/ressources/ressources.qrc

echo "done"
