


[UpdateC]
Meter=Shape
X=r
Y=#GlobalP#R
Shape=Rectangle 0,0,#ShadeW#,#SimpleH#,(#R#*1.5),(#R#*1.5) | StrokeWidth 0
Group=UpdateC
Hidden=1

[UpdateB]
Meter=Shape
Shape=Rectangle 0,0,#ShadeW#,#SimpleH# | StrokeWidth 0 | Fill Color #MainColor#
Container=UpdateC
Leftmouseupaction=[https://github.com/EnhancedJax/MIUI-Shade/releases/latest]
Hidden=1
Group=UpdateC

[Update]
meter=Image
ImageName=#@#Icons\Update.png
X=(22*#scale#)
Y=(16*#scale#)
W=(16*#scale#)
H=(16*#scale#)
ImageTint=#OppositeColor#
Container=UpdateC
Hidden=1
Group=UpdateC

[UpdateHead]
Meter=String
MeterStyle=S
X=(5*#scale#)R
Y=(16*#scale#/2)r
W=(#ShadeW#-#SimpleH#)
StringAlign=LeftCenter
ClipString=2
FontWeight=400
Text=System
FontSize=(8*#scale#)
FontColor=#OppositeColor#
Container=UpdateC
Hidden=1
Group=UpdateC

[UpdateMAin]
Meter=String
MeterStyle=S
X=(22*#scale#)
Y=(15*#scale#)r
Text=Update for MIUI available#CRLF#Click here to download
FontSize=(12*#scale#)
FontColor=#OppositeColor#
MeasureName=mCurrentTemperature
MeasureName2=mLocationCity
MeasureName3=mCurrentPhrase
InlinePattern=#CRLF#(.*)
InlineSetting=Size | (10*#scale#)
InlinePattern2=#CRLF#(.*)
InlineSetting2=Color | #OppositeColor#,150
Container=UpdateC
Hidden=1
Group=UpdateC


;====================================



[UpdateWeb]
Measure=WebParser
URL=https://api.github.com/repos/EnhancedJax/MIUI-Shade/releases/latest
RegExp=(?siU)\{.*"tag_name":"v(.*)".*}
UpdateDivider=(#Animation# = 1 ? 50 : 1)
FinishAction=[!Delay 1000][!EnableMeasure mC4U][!UpdateMeasure mC4U]

[mVer]
Measure=WebParser
URL=[UpdateWeb]
StringIndex=1
UpdateDivider=(#Animation# = 1 ? 50 : 1)

[mC4U]
Measure=Calc
DynamicVariables=1
Disabled=1
IfconditionMode=1
IfCondition=mC4U < #Version#
IfTrueAction=[!ShowMeterGroup UpdateC][!SetOption UpdateMAin Text "You are currently on a beta build.#CRLF#Build might not be stable"][!UpdateMEter UpdateMAin][!Redraw]
IfCondition2=mC4U > #Version#
IfTrueAction2=[!ShowMeterGroup UpdateC][!Redraw]