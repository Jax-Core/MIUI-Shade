
[Time]
Meter=String
FontSize=(37*#Scale#)
Container=C
MeasureName=mTime
MeterStyle=S
UpdateDivider=(#Animation# = 1 ? 50 : 1)

[Date]
Meter=String
FontSize=(12*#Scale#)
X=(5*#Scale#)
Y=(60*#Scale#)
Container=C
MeasureName=mDate
MeterStyle=S
UpdateDivider=(#Animation# = 1 ? 50 : 1)

[Settings]
Meter=Image
ImageNAme=#@#Icons\Settings.png
X=(#ShadeW#-24*#Scale#)
Y=((60-24)*#Scale#)
W=(24*#Scale#)
H=(24*#Scale#)
SolidColor=0,0,0,1
Container=C
LeftMouseUpAction=[!ActivateConfig "MIUI-Shade\@Settings" "Info.ini"][!DeactivateConfig]


[mBattery]
Measure=Plugin
Plugin=PowerPlugin
PowerState=Percent
UpdateDivider=(#Animation# = 1 ? 50 : 1)
OnChangeAction=[!UpdateMeter Power][!Redraw]

[Power]
Meter=Shape
X=(#ShadeW#-36*#Scale#)
Y=(65*#Scale#)
Container=C
DynamicVariables=1
Shape=Rectangle 0,0,(30*[mBattery]/100),12,2,2 | StrokeWidth 0 | Fill Color 255,255,255,50  | Scale #Scale#,#Scale#,0,0
Shape2=Rectangle 0,0,30,12,2,2 | StrokeWidth (2*#Scale#) | Fill Color 0,0,0,0 | Stroke Color 255,255,255 
Shape3=Rectangle 33,3,1,6,0.25,0.25 | StrokeWidth 0 | Fill Color 255,255,255 
Shape4=Combine Shape2 | Union Shape3  | Scale #Scale#,#Scale#,0,0

[PowerPercent]
Meter=String
MeterStyle=S
MeasureName=mBattery
X=(15*#scale#)r
Y=(7*#Scale#)r
FontSize=(6*#scale#)
FontWeight=800
UpdateDivider=(#Animation# = 1 ? 50 : 1)
StringAlign=CenterCenter
Container=C

[WifiStrength]
Meter=Image
ImageName=
X=((-5-28-15)*#scale#)r
Y=(-16*#scale#)r
W=(28*#Scale#)
H=(28*#Scale#)
Container=C