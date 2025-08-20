function [rate,collison] = success_rate(conf,iter)
    obj.FilePath = conf.mySavePath;
    for idx = 1:iter
        obj.FileName = [conf.mySaveFileName,'\Parallel', num2str(idx)];
        folderPath = strcat(obj.FilePath, filesep, datestr(datetime('today'), 'yyyymmdd'), filesep, obj.FileName);
%         folderPath   = makeFolder(obj);
        load(strcat(folderPath, filesep, 'collision.mat'), 'collision_flag');
        collison(idx) = collision_flag;
    end
    rate = 1 - sum(collison)/iter;
end
