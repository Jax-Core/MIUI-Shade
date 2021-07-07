[mState]
Measure=NowPlaying
PlayerName=#NPName#
PlayerType=State
IfCondition=mState = 1
IfTrueAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw]
IfCondition2=mState = 2
IfTrueAction2=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw]
IfCondition3=mState = 0
IfTrueAction3=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw]
IfConditionMode=0
OnchangeAction=[!UpdateMeter *]
DynamicVariables=1
UpdateDivider=(#Animation# = 1 ? 50 : 1)

[mCover]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Cover
Substitute="":"#@#Images\Default.png"
UpdateDivider=(#Animation# = 1 ? 50 : 1)

[mArtist]
Measure=NowPlaying
PlayerName=[mState]
OnchangeAction=[!UpdateMeasureGroup Music][!UpdateMeter *][!Redraw]
PlayerType=Artist
Substitute="":"Fetching..."
UpdateDivider=(#Animation# = 1 ? 50 : 1)

[mTrack]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Title
Substitute="":"Fetching..."
UpdateDivider=(#Animation# = 1 ? 50 : 1)

[mProgress]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Progress
Substitute="NaN":"1"
DynamicVariables=1
UpdateDivider=(#Animation# = 1 ? 50 : 1)

[mCurrentPosition]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Position
UpdateDivider=(#Animation# = 1 ? 50 : 1)

[mLength]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Duration
UpdateDivider=(#Animation# = 1 ? 50 : 1)

[mHeart]
Measure=NowPlaying
PlayerName=[mState]
PlayerType=Rating
IfCondition=mHeart = 0
IfTrueAction=[!SetOption Heart MeterStyle "EmptyHeart"]
IfFalseAction=[!SetOption Heart MeterStyle "FullHeart"]
UpdateDivider=(#Animation# = 1 ? 50 : 1)