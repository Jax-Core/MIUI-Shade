[Variables]
Drag=0

[HotkeysTitle]
Meter=String
Text=Activation
MeterStyle=Set.String:S | Set.OptionCat:S

[Option01]
Meter=String
X=r
Text=HotKey
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option02]
Meter=String
Text=Disable when fullscreen
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:123]
Meter=Shape
MeterStyle=Set.Div:S
[Option03]
Meter=String
Text=Index of screen to display on
MeterStyle=Set.String:S | Set.OptionName:S
;================================================================================================================================================================================

[DragTitle]
Meter=String
Text=Dragging activation
MeterStyle=Set.String:S | Set.OptionCat:S

[Option30]
Meter=String
Text=Drag to launch skin
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:238]
Meter=Shape
MeterStyle=Set.Div:S
[Option31]
Meter=String
Text=Dragging size
MeterStyle=Set.String:S | Set.OptionName:S


[Time]
Meter=String
Text=Time & weather
MeterStyle=Set.String:S |  Set.OptionCat:S

[Option11]
Meter=String
Text=Time format
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S19032213138]
Meter=Shape
MeterStyle=Set.Div:S
[Option21]
Meter=String
Text=Show weather notification
MeterStyle=Set.String:S | Set.OptionName:S
[Set.Div:S190322131238]
Meter=Shape
MeterStyle=Set.Div:S
[Option22]
Meter=String
Text=Weather location & units
MeterStyle=Set.String:S | Set.OptionName:S

;================================================================================================================================================================================




;================================================================================================================================================================================

[Button01]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option01:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!CommandMeasure Func "startSide('Hotkey')"]
[Value01]
Meter=String
Text=#KeyInString#
MeterStyle=Set.String:S | Set.Value:S
[HideOnFullScreen]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option02:Y]-#Set.P#+(-20/2+8)*[Set.S])
[ScreenNumber]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option03:Y]-#Set.P#+(-30/2+8)*[Set.S])
Type=Int|1|100
[Value03]
Meter=String
Text=#ScreenNumber#
MeterStyle=Set.String:S | Set.Value:S

[Info:DragTitle]
Meter=Shape
MeterStyle=Set.RectButton:S
Y=([DragTitle:Y]-#Set.P#+(-30/2+8)*[Set.S])
[Info01]
Meter=String
MeterStyle=Set.String:S | Set.Icon:S

[Drag]
Meter=Shape
MeterStyle=Set.Bool:S | Drag#Drag#
Y=([Option30:Y]-#Set.P#+(-20/2+8)*[Set.S])
[Drag0]
Leftmouseupaction=[!ActivateConfig "#Skin.Name#\Activator"][!Refresh]
[Drag1]
Leftmouseupaction=[!DeactivateConfig "#Skin.Name#\Activator"][!Refresh]

[Detect.Size]
Meter=Shape
MeterStyle=Set.Textbox:S
Y=([Option31:Y]-#Set.P#+(-30/2+8)*[Set.S])
Type=Int|1|100
Leftmouseupaction=[!SetVariable Editing "#CURRENTSECTION#"][!SetOption Input:M X "([#CURRENTSECTION#:X]+5)"][!SetOption Input:M Y "([#CURRENTSECTION#:Y]+5)"][!CommandMeasure Input:M "ExecuteBatch 2"]
[Value31]
Meter=String
Text=#Detect.Size#
MeterStyle=Set.String:S | Set.Value:S

[Button11]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option11:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!WriteKeyvalue Variables Skin.Name """#JaxCore""" "#@#SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page GlobalVars "#@#SecVar.inc"][!Refresh]
[Icon11]
Meter=String
Text=[\xe895]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
FontColor=#Set.Subtext_Color#
MeterStyle=Set.String:S | Set.Value:S
[Value11]
Meter=String
X=(-25*[Set.S])r
Y=r
Text=Change global variable
FontColor=#Set.Subtext_Color#
MeterStyle=Set.String:S | Set.Value:S

[Weather]
Meter=Shape
MeterStyle=Set.Bool:S
Y=([Option21:Y]-#Set.P#+(-20/2+8)*[Set.S])

[Button22]
Meter=Shape
MeterStyle=Set.Button:S
Y=([Option22:Y]-#Set.P#+(-30/2+8)*[Set.S])
Act=[!WriteKeyvalue Variables Skin.Name """#JaxCore""" "#@#SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page GlobalVars "#@#SecVar.inc"][!Refresh]
[Icon22]
Meter=String
Text=[\xe895]
FontFace=Material Icons Round
FontSize=(14*[Set.S])
FontColor=#Set.Subtext_Color#
MeterStyle=Set.String:S | Set.Value:S
[Value22]
Meter=String
X=(-25*[Set.S])r
Y=r
Text=Change global variable
FontColor=#Set.Subtext_Color#
MeterStyle=Set.String:S | Set.Value:S

[ActiveChecker2]
Measure=Plugin
Plugin=ConfigActive
ConfigName=#Skin.Name#\Activator
IfCondition=ActiveChecker2 = 1
IfTrueAction=[!SetVariable Drag 1][!UpdateMeter Drag][!Redraw]



;================================================================================================================================================================================
[Input:M]
Command2=[!CommandMeasure Func "processInput('#Editing#', [[$UserInput$]])"][!Refresh "#Skin.Name#\Activator"]

@includeKeys=#SKINSPATH##Skin.Name#\@Resources\Actions\HotKeys.ini