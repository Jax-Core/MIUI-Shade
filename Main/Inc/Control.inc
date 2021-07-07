
[MainBox]
Meter=Shape
Y=(85*#Scale#+#GlobalP#)
Shape=Rectangle 0,0,#ShadeW#,(#BoxP#*3+(64+16+4)*#scale#),#R#,#R# | Fill Color #MainColor# | StrokeWidth 0
Container=C

[CtrlCirc]
X=((12+31)*#Scale#)R
Y=(-(32-12)*#scale#)r
Shape=Ellipse 32,32,32,32 | StrokeWidth 0 | Scale #Scale#,#Scale#,0,0 | Extend Fill
Container=C
[CtrlImg]
X=((32-12)*#scale#)r
Y=((32-12)*#scale#)r
W=(24*#Scale#)
H=(24*#Scale#)
Container=C
ImageTint=#OppositeCOlor#

[CircInternet]
Meter=Shape
X=#BoxP#r
Y=#BoxP#r
Fill=Fill Color #OffColor#
MeterStyle=CtrlCirc
LeftMouseUpAction=[!UpdateMEasure mToggleInternet]
[ImgInternet]
Meter=Image
ImageName=#@#Icons\Data.png
MeterStyle=CtrlImg

[CircWifi]
Meter=Shape
MeterStyle=CtrlCirc
Fill=Fill Color #OffColor#
LeftMouseUpAction=["ms-availablenetworks:"]
[ImgWifi]
Meter=Image
ImageName=#@#Icons\Wifi.png
MeterStyle=CtrlImg

[CircBluetooth]
Meter=Shape
MeterStyle=CtrlCirc
Fill=Fill Color #OffColor#
LeftMouseUpAction=#BT_ToggleBluetooth#
RightMouseUpAction=["ms-settings:bluetooth"]
[ImgBluetooth]
Meter=Image
ImageName=#@#Icons\Bluetooth.png
MeterStyle=CtrlImg

[CircScreenshot]
Meter=Shape
MeterStyle=CtrlCirc
Fill=Fill Color #OffColor#
LeftMouseUpAction=[!UpdateMEasure mToggle][!Delay #TweenTime1#]["#@#Actions\AHK.exe" "#@#Actions\Source Code\Snip.ahk"]
RightMouseUpAction=["#@#Actions\AHK.exe" "#@#Actions\Source Code\Snip.ahk"]
[ImgScreenshot]
Meter=Image
ImageName=#@#Icons\Screenshot.png
MeterStyle=CtrlImg

[CircLock]
Meter=Shape
MeterStyle=CtrlCirc
Fill=Fill Color #OffColor#
LeftMouseUpAction=[!UpdateMEasure mToggle][!Delay #TweenTime1#][rundll32.exe user32.dll LockWorkStation]
[ImgLock]
Meter=Image
ImageName=#@#Icons\Lock.png
MeterStyle=CtrlImg

[Divider]
Meter=Shape
X=#BoxP#
Y=(24*#Scale#+#BoxP#)R
Shape=Line 0,0,(#ShadeW#-#BoxP#*2),0 | StrokeWidth 1 | Stroke Color 53, 53, 55
Container=C

[HeadIcon]
Meter=Shape
X=r
Y=(#BoxP#/2)r
Shape=Ellipse (8*#Scale#),(8*#Scale#),(8*#Scale#),(8*#Scale#) | StrokeWidth 1 | Stroke Color #OppositeColor#,150 | Fill Color 0,0,0,0
Shape2=Ellipse (8*#Scale#),(8*#Scale#),(6*#Scale#),(6*#Scale#) | StrokeWidth 0 | Fill Color #OppositeColor#,150
Container=C

[InternetDebug]
Meter=String
MeterStyle=S
X=(10*#scale#)R
Y=(8*#Scale#)r
StringAlign=LeftCenter
FontSize=(8*#Scale#)
FontColor=#OppositeColor#,150
MeasureName=InternetDownloadSpeed
MeasureName2=InternetUploadSpeed
Text=Download: %1b     Upload: %2b
AutoScale=1k
Container=C
UpdateDivider=(#Animation# = 1 ? 50 : 1)


;===========================================================

