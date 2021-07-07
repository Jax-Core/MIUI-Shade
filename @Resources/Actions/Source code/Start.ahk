#SingleInstance Force
#NoTrayIcon
SetTitleMatchMode, 2
DetectHiddenWindows, On
numberkeys := 0


IniRead, OutputVar, Hotkeys.ini, Variables, Key

Hotkey,%OutputVar%,Button
Return

Button:
Run "C:\Program Files\Rainmeter\Rainmeter.exe "!UpdateMeasure "mToggle" "MIUI-Shade\Main" "
Unload := 1
Return