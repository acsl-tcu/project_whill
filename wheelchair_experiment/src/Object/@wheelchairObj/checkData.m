function [] = checkData(obj, Data, Md)
    switch Md
        case "estimate"
            tmp = arrayfun(@(X) isfield(Data, obj.Names(X)), obj.est);
            slct= [tmp, true(size(obj.ctl))];
        case "control"
            tmp = arrayfun(@(X) isfield(Data, obj.Names(X)), obj.ctl);
            slct= [true(size(obj.est)), tmp];
        otherwise
            error('Wrong number. Select the correct number again.');
    end
    if  ~all(tmp)
        vrb = cell2mat(cellfun(@(X) [X, ', '], obj.Names(~slct), 'UniformOutput', false));
        if sum(~tmp) == 1
            str = ['The variable ', vrb(1: end-2), ' is not stored in the structure.'];
        else
            str = ['The variables ',vrb(1: end-2), ' are not stored in the structure.'];
        end
        error(char(str));
    end
end