function Update()
    local MyMeasure = SKIN:GetMeasure('MeasureIsFullScreen')
    local mString = MyMeasure:GetStringValue()
    local mNum = MyMeasure:GetValue()
    local mVar = SKIN:GetVariable('HideOnFullScreen', 'n/a')
    if mString:match('Rainmeter%.exe') then
        mBool = 1
    else
        mBool = 0
    end
    local check = (mNum .. mVar .. mBool)
    if string.match(check, '110') then
        SKIN:Bang('!DisableMeasure', 'mToggle')
    else
        SKIN:Bang('!EnableMeasure', 'mToggle')
    end
end
