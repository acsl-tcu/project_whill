function [modelptCOG_crr,modelptCOG] = pcfitptCOG(point,xhat) % ,pxhat,imm
    modelptCOG = double([mean(point.Location(:,1));mean(point.Location(:,2))]); % 点群重心

    axisoffset = xhat(end-1)-(xhat(end-1)-xhat(end)).*sin(round(xhat(3))/4)^2;% xhat(8) 姿勢角に合わせたオフセット補正
    % pv = pxhat(4).*[cos(pxhat(3));sin(pxhat(3))];
    % modelptCOG_crr = modelptCOG + (xhat(8).*[abs(cos(xhat(3)));sin(xhat(3))]);
    modelptCOG_crr = modelptCOG + (axisoffset.*xhat(end).*[abs(cos(xhat(3)));sin(xhat(3))]); % 胴体中心に近づけるためのオフセット
    % modelptCOG_crr = modelptCOG + sign(dot(modelptCOG,xhat(4:5))).*(xhat(8).*[cos(xhat(3));sin(xhat(3))]);

    % S = c*Pbar*c'+R;
    % score = likelihood(imm.TrackingFilters{3,1},modelptCOG_crr);
    % if forassociate
    %     Ytilde = modelptCOG-Yhbar;
    % else
    %     Ytilde = modelptCOG_crr-Yhbar;
    % end
    % MD = sqrt(Ytilde'/S*Ytilde);
end