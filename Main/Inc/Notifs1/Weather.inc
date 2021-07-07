


[WeatherC]
Meter=Shape
X=r
Y=#GlobalP#R
Shape=Rectangle 0,0,#ShadeW#,#SimpleH#,(#R#*1.5),(#R#*1.5) | StrokeWidth 0

[WeatherB]
Meter=Shape
Shape=Rectangle 0,0,#ShadeW#,#SimpleH# | StrokeWidth 0 | Fill Color #MainColor#
Container=WeatherC

[Cloud]
meter=Image
ImageName=#@#Icons\Cloud.png
X=(22*#scale#)
Y=(16*#scale#)
W=(16*#scale#)
H=(16*#scale#)
ImageTint=#OppositeColor#
Container=WeatherC

[SHead]
Meter=String
MeterStyle=S
X=(5*#scale#)R
Y=(16*#scale#/2)r
W=(#ShadeW#-#SimpleH#)
StringAlign=LeftCenter
ClipString=2
FontWeight=400
Text=Google
FontSize=(8*#scale#)
FontColor=#OppositeColor#
Container=WeatherC

[SMAin]
Meter=String
MeterStyle=S
X=(22*#scale#)
Y=(15*#scale#)r
Text=%1 in %2#CRLF#%3
FontSize=(12*#scale#)
FontColor=#OppositeColor#
MeasureName=mCurrentTemperature
MeasureName2=mLocationCity
MeasureName3=mCurrentPhrase
InlinePattern=#CRLF#(.*)
InlineSetting=Size | (10*#scale#)
InlinePattern2=#CRLF#(.*)
InlineSetting2=Color | #OppositeColor#,150
Container=WeatherC


@includeWeather=#@#Includes\GlobalWeather.inc