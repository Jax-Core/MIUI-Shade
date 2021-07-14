

;==============================================================================================
;==============================================================================================
;==============================================================================================

[MainC]
Measure=Plugin
Plugin=Chameleon
Type=File
Path=#@#Images\Default.png
Format=Dec
UpdateDivider=(#Animation# = 1 ? 50 : 1)

[LC1]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Light1
UpdateDivider=(#Animation# = 1 ? 50 : 1)

[BGC]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Background1
UpdateDivider=(#Animation# = 1 ? 50 : 1)

[FGC1]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Foreground1
UpdateDivider=(#Animation# = 1 ? 50 : 1)

[FGC2]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Foreground2
UpdateDivider=(#Animation# = 1 ? 50 : 1)

; [AvC]
; Measure=Plugin
; Plugin=Chameleon
; Parent=MainC
; Color=Average
; Group=Music

[Luminance]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Luminance
OnChangeAction=[!UpdateMeterGroup DynamicColors]
UpdateDivider=(#Animation# = 1 ? 50 : 1)

; [BackgroundColor]
; Measure=Calc
; IfConditionMode=1
; IfCondition=Luminance > 1
; IfTrueAction=[!SetVariable BackgroundColor "[FGC1]"][!SetVariable TextColor "[BGC]"][!SetVariable AltTextColor "[BGC]"]
; IfFalseAction=[!SetVariable BackgroundColor "[BGC]"][!SetVariable TextColor "[FGC2]"][!SetVariable AltTextColor "[FGC1]"]
; ; IfCondition2=Luminance > 0.5
; ; IfTrueAction2=[!SetVariable ContrastTextColor "0,0,0"]
; ; IfFalseAction2=[!SetVariable ContrastTextColor "255,255,255"]
; OnUpdateAction=

;==============================================================================================
;==============================================================================================
;==============================================================================================

[MusicB]
Meter=Shape
X=r
Y=#GlobalP#R
Shape=Rectangle 0,0,#ShadeW#,#MusicH#,(#R#*1.5),(#R#*1.5) | StrokeWidth 0 | Fill Color [BGC]
DynamicVariables=1
Hidden=([mState] > 0 ? 0 : 1)
Group=DynamicColors | Music

[MusicImageC]
Meter=Shape
X=r
Y=r
Hidden=([mState] > 0 ? 0 : 1)
Group=Music
DynamicVariables=1
Shape=Rectangle 0,0,#ShadeW#,#MusicH#,(#R#*1.5),(#R#*1.5) | StrokeWidth 0 | Fill LinearGradient MyFillGradient
MyFillGradient=180 | 0,0,0,0 ; 0.65 | 0,0,255,255 ; 1.0

[MusicImg]
Meter=Image
ImageName=[mCover]
X=(#ShadeW#-#MusicH#)r
W=#MusicH#
H=#MusicH#
PreserveAspectRatio=2
Container=MusicImageC
DynamicVariables=1

[MusicC]
Meter=Shape
X=r
Y=r
Hidden=([mState] > 0 ? 0 : 1)
Group=Music
DynamicVariables=1
Shape=Rectangle 0,0,#ShadeW#,#MusicH#,(#R#*1.5),(#R#*1.5) | StrokeWidth 0


[MusicHead]
Meter=String
MeterStyle=S
X=(22*#Scale#)
Y=((22*#Scale#)-5)
W=(#ShadeW#-#MusicH#)
ClipString=2
FontWeight=400
FontFace=Open Sans
Text=#NPName#
FontSize=(8*#scale#)
FontColor=[FGC2]60
DynamicVariables=1
Group=DynamicColors
Container=MusicC

[MusicName]
Meter=String
MeterStyle=S
X=r
Y=(20*#scale#)r
W=(#ShadeW#-#MusicH#)
ClipString=1
FontWeight=600
FontFace=Open Sans
FontSize=(15*#scale#)
FontColor=[FGC2]
DynamicVariables=1
MeasureName=mTrack
Group=DynamicColors
Container=MusicC
[SArtist]
Meter=String
MeterStyle=S
X=r
Y=(35*#Scale#)r
W=(#ShadeW#-#MusicH#)
ClipString=1
FontWeight=600
FontFace=Open Sans
FontSize=(8*#scale#)
FontColor=[FGC1]
DynamicVariables=1
MeasureName=mArtist
Group=DynamicColors
Container=MusicC

[Heart]
Meter=Image
X=r
Y=(30*#scale#)r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]
DynamicVariables=1
Group=DynamicColors
Container=MusicC
[FullHeart]
ImageName=#@#Icons\HeartFull.png
LeftMouseUpAction=[!SetOption Heart MeterStyle EmptyHeart][!UpdateMeter Heart][!Redraw][!CommandMeasure mState "ToggleThumbsDown"]
[EmptyHeart]
ImageName=#@#Icons\Heart.png
LeftMouseUpAction=[!SetOption Heart MeterStyle Fullheart][!UpdateMeter Heart][!Redraw][!CommandMeasure mState "ToggleThumbsUp"]


[Previous]
Meter=Image
ImageName=#@#Icons\Previous.png
X=(20*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]
DynamicVariables=1
Group=DynamicColors
LeftMouseUpAction=[!CommandMeasure mState "Previous"]
Container=MusicC


[PlayPause]
Meter=Image
MeterStyle=
X=(20*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]
DynamicVariables=1
Group=DynamicColors
Container=MusicC
[Play]
ImageName=#@#Icons\Play.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw][!CommandMeasure mState "PlayPause"]
[Pause]
ImageName=#@#Icons\Pause.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw][!CommandMeasure mState "PlayPause"]

[Next]
Meter=Image
ImageName=#@#Icons\Next.png
X=(20*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]
DynamicVariables=1
Group=DynamicColors
LeftMouseUpAction=[!CommandMeasure mState "Next"]
Container=MusicC

[ProgBar]
Meter=Shape
X=(22*#Scale#)
Y=(40*#scale#)r
Shape=Line 0,0,(#ShadeW#-(22*#Scale#)*2),0 | StrokeWidth 2 | Fill Color 0,0,0,1 | Stroke Color [FGC2]60 | StrokeStartCap Round | StrokeEndCap Round
Shape2=Line 0,0,((#ShadeW#-(22*#Scale#)*2)*[mProgress]/100),0 | StrokeWidth 2 | Fill Color 0,0,0,1 | Stroke Color [FGC2] | StrokeStartCap Round | StrokeEndCap Round
Shape3=Ellipse ((#ShadeW#-(22*#Scale#)*2)*[mProgress]/100),0,4,4 | strokeWidth 0 | Fill Color [FGC2]
DynamicVariables=1
UpdateDivider=(#Animation# = 1 ? 50 : 1)
Group=DynamicColors
LeftMouseUpAction=[!SetOption PosCalc Formula "($MouseX$/(#ShadeW#-(22*#Scale#)*2)*100)"][!UpdateMeasure PosCalc]
Container=MusicC
[PosCalc]
Measure=calc
OnUpdateAction=[!CommandMeasure mState "SetPosition [PosCalc]"]
Disabled=1
DynamicVariables=1
UpdateDivider=-1
Group=NUOL
Container=MusicC

[CurrentTime]
Meter=String
MeterStyle=S
X=r
Y=R
FontColor=[FGC2]
DynamicVariables=1
FontSize=(8*#scale#)
MeasureName=mCurrentPosition
UpdateDivider=(#Animation# = 1 ? 50 : 1)
Group=DynamicColors
Container=MusicC
[MediaLength]
Meter=String
MeterStyle=S
X=(#ShadeW#-(22*#Scale#)*2)r
Y=r
FontColor=[FGC2]
StringAlign=Right
DynamicVariables=1
FontSize=(8*#scale#)
MeasureName=mLength
Group=DynamicColors
Container=MusicC




@includeMusic=#@#Includes\Global#Player#.inc