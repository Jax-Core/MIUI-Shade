

;========================================
;Uptime
;========================================

[MeasureUptime]
Measure=Uptime
Format="%4!i! days, %3!i! hours, %2!i! minutes %1!i! seconds"
UpdateDivider=(#Animation# = 1 ? 50 : 1)

;========================================
;Internet
;========================================

; [InternetType]
; Measure=Plugin
; Plugin=SysInfo
; SysInfoType=ADAPTER_TYPE
; SysInfoData=Best
; UpdateDivider=-1
; IfCondition=InternetType=6
; IfTrueAction=[!SetVariable NetType Ethernet][!UpdateMeasure InternetStatus]
; IfCondition2=InternetType=71
; IfTrueAction2=[!SetVariable NetType Wifi][!UpdateMeasure InternetStatus]

[mWifiStrength]
Measure=Plugin
Plugin=WiFiStatus
WiFiInfoType=Quality
IfCondition=mWifiStrength < 20
IfTrueAction=[!SetOption WifiStrength ImageName ""][!UpdateMeter WifiStrength]
IfCondition2=(mWifiStrength >= 20) && (mWifiStrength < 70)
IfTrueAction2=[!SetOption WifiStrength ImageName "#@#Icons\Wifi_1.png"][!UpdateMeter WifiStrength]
IfCondition3=(mWifiStrength >= 70) && (mWifiStrength < 90)
IfTrueAction3=[!SetOption WifiStrength ImageName "#@#Icons\Wifi_2.png"][!UpdateMeter WifiStrength]
IfCondition4=(mWifiStrength >= 90)
IfTrueAction4=[!SetOption WifiStrength ImageName "#@#Icons\Wifi_3.png"][!UpdateMeter WifiStrength]
UpdateDivider=(#Animation# = 1 ? 50 : 1)
[InternetName]
Measure=PLUGIN
Plugin=WifiStatus
WiFiInfoType=SSID
IfMatch=-1
IfMatchAction=[!SetOption CircWifi Fill "Fill Color #Offcolor#"][!SetOption ImgWifi ImageTint "#OppositeColor#"][!UpdateMeter CircWifi][!UpdateMeter ImgWifi][!Redraw]
IfNotmatchaction=[!SetOption CircWifi Fill "Fill Color #Oncolor#"][!SetOption ImgWifi ImageTint "255,255,255"][!UpdateMeter CircWifi][!UpdateMeter ImgWifi][!Redraw]
UpdateDivider=(#Animation# = 1 ? 50 : 1)
[InternetStatus]
Measure=PLUGIN
Plugin=SysInfo
SysInfoType=INTERNET_CONNECTIVITY
Substitute="-1.0":"Offline","1.0":"Connected"
DynamicVariables=1
IfCondition=InternetStatus = 1
IfTrueAction=[!SetOption CircInternet Fill "Fill Color #Oncolor#"][!SetOption ImgInternet ImageTint "255,255,255"][!UpdateMeter CircInternet][!UpdateMeter ImgInternet][!Redraw]
IfFalseAction=[!SetOption CircInternet Fill "Fill Color #OffColor#"][!SetOption ImgInternet ImageTint "#OppositeColor#"][!UpdateMeter CircInternet][!UpdateMeter ImgInternet][!Redraw]
UpdateDivider=(#Animation# = 1 ? 50 : 1)
[mAUTH]
Measure=PLUGIN
Plugin=WifiStatus
WiFiInfoType=AUTH
Substitute="-1":""
UpdateDivider=(#Animation# = 1 ? 50 : 1)
[InternetDownloadSpeed]
Measure=NetIn
Interface=Best
MinValue=0
; AverageSize=5
UpdateDivider=(#Animation# = 1 ? 50 : 1)
[InternetUploadSpeed]
Measure=NetOut
Interface=Best
MinValue=0
; AverageSize=5
UpdateDivider=(#Animation# = 1 ? 50 : 1)


[mToggleInternet]
Measure=Calc
IfCondition=InternetStatus = 1
IfTrueAction=[!CommandMeasure MeasureTurnOff "Run"][!SetOption CircInternet Fill "Fill Color #Offcolor#"][!SetOption ImgInternet ImageTint "#OppositeColor#"][!UpdateMeter CircInternet][!UpdateMeter ImgInternet][!Redraw]
IfFalseAction=[!CommandMeasure MeasureTurnOn "Run"][!SetOption CircInternet Fill "Fill Color #Oncolor#"][!SetOption ImgInternet ImageTint "255,255,255"][!UpdateMeter CircInternet][!UpdateMeter ImgInternet][!Redraw]
Disabled=1
Group=NUOL

[MeasureTurnOff]
Measure=Plugin
Plugin=RunCommand
Parameter=ipconfig /release
State=Hide
[MeasureTurnOn]
Measure=Plugin
Plugin=RunCommand
Parameter=ipconfig /renew
State=Hide