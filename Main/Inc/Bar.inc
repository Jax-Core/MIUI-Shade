

[MainBar]
Meter=Shape
Y=([MainBox:YH]-#P#+#GlobalP#)
LeftMouseDownAction=[!CommandMeasure VolumeMouse "Start"]
LeftMouseUpAction=[]
Shape4=Combine Shape3 | Intersect Shape2
Container=C
Group=ANI
DynamicVariables=1
meterStyle=BarColor#ColorMode#
[BarColor0]
Shape=Rectangle 0,0,#ShadeW#,(#BarH#),#R#,#R# | Fill Color #MainColor# | StrokeWidth 0
Shape2=Rectangle 0,0,#ShadeW#,(#BarH#),#R#,#R# | StrokeWidth 0
Shape3=Rectangle 0,0,(#ShadeW#*[mVolume:]/100),(#BarH#) | Fill Color #OppositeColor#,160 | StrokeWidth 0
[BarColor1]
Shape=Rectangle 0,0,#ShadeW#,(#BarH#),#R#,#R# | Fill Color 160, 163, 168 | StrokeWidth 0
Shape2=Rectangle 0,0,#ShadeW#,(#BarH#),#R#,#R# | StrokeWidth 0
Shape3=Rectangle 0,0,(#ShadeW#*[mVolume:]/100),(#BarH#) | Fill Color #MainColor# | StrokeWidth 0

[VolumeMin]
Meter=Image
ImageName=#@#Icons\VolumeMin.png
X=((#BarH#-16*#Scale#)/2)r
Y=((#BarH#-16*#Scale#)/2)r
W=(16*#Scale#)
Container=C

[VolumeMax]
Meter=Image
ImageName=#@#Icons\VolumeMax.png
X=(#ShadeW#-(#BarH#))r
Y=r
W=(16*#Scale#)
Container=C

;============================================

[mVolume]
Measure=Plugin
Plugin=Win7AudioPlugin
DynamicVariables=1
OnChangeAction=[!Setvariable SliderX ([mVolume:]/100*#ShadeW#+#SliderM#)][!UpdateMeter MainBar][!Redraw]
UpdateDivider=50


[SliderPercent]
Measure=Calc
Formula=((#SliderX#-(#SliderM#))*100/(((#SliderM#)+#ShadeW#)-(#SliderM#)))
OnUpdateAction=[!CommandMeasure "mVolume" "SetVolume [#CURRENTSECTION#]"][!UpdateMeasure mVolume]
DynamicVariables=1
Disabled=1
Group=NUOL

[VolumeMouse]
Measure=Plugin
Plugin=Mouse
; this measure uses the Plugin:Mouse
LeftMouseDragAction=[!SetVariable SliderX "(Clamp(($MouseX$),(#SliderM#),((#SliderM#)+#ShadeW#)))"][!UpdateMeasure SliderPercent]
; actions to be executed when the mouse drags. The first bang gets the mouse value and make sure it's in the slider. The bangs after that updates the required measures and the slider.
LeftMouseUpAction=[!CommandMeasure VolumeMouse "Stop"]
; actions to be executed after the mouse click is lifted. The first bang stops the measure to retrieve information from mouse dragging.
RelativeToSkin=1
RequireDragging=1
DynamicVariables=1