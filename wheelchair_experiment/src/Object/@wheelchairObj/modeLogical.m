function ret = modeLogical(obj, RawData)
    ret = true;
    switch obj.Mode
        case {'Numerical', 1}
            ret = ge(RawData.T, obj.EndTime);
        case {'Physics',   2}
            ret = isletter(kbhit);
        case {'Expriment', 3}
            % isletter:�p���������o��
            % �����Ŏ����̏I�������ɂ߂Ă���
            ret = isletter(kbhit);
        case {'Offline',  4}
            ret = ge(RawData.T, obj.EndTime);
    end
end