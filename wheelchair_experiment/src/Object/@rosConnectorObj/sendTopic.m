function sendTopic(obj, DataSet)
    obj.pubMessage{obj.cmdVel}.Linear.X  = DataSet.V(1,1);
    obj.pubMessage{obj.cmdVel}.Angular.Z = DataSet.V(2,1);
    send(obj.pubTopic{obj.cmdVel}, obj.pubMessage{obj.cmdVel});
end