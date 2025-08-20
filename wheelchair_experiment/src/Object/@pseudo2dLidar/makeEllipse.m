function data = makeEllipse(~, x, y, th, a, b)
    %- Function for making ellipses -%
    Te = 0:0.1:360;
    Ne = length(Te);
    Ce = [x*ones(1,Ne); y*ones(1,Ne)];
    Xe = [a*cosd(Te); b*sind(Te)];
    Re = [cosd(th), -sind(th); sind(th), cosd(th)];
    data = Re*Xe + Ce;
end