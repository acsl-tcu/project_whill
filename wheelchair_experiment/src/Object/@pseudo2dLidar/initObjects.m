function [room, object] = initObjects(obj)
   %% Initial settings 
    room  = {};
    object= {};

   %% makinf your environment 
    room{obj.X,1}   = [-200; 200; 200; -200];
    room{obj.Y,1}   = [-1; -1; 1; 1];

    data = makeEllipse(obj, 5, -0.5, 0, 0.25, 0.25);
    object{obj.X,1} = data(1,:)';
    object{obj.Y,1} = data(2,:)';
end