function [px,pw,pv] = Resampling(obj,ppu,pw)
    %RESAMPLING ���̊֐��̊T�v�������ɋL�q
    %   �ڍא����������ɋL�q
%     if obj.Resamplingmode == "LVS"
        NP = obj.NP;
        px = reshape(ppu(2,:,:),[],NP);
        v  = reshape(ppu(1,:,:),[],NP); 
        %px:�p�[�e�B�N���Cpw:�d��
        %���T���v�����O�����{����֐�
        %�A���S���Y����Low Variance Sampling
        wcum=cumsum(pw);
        base=cumsum(pw*0+1/NP)-1/NP;%������������O��base
        resampleID=base+rand/NP;%���[���b�g�𗐐������₷
        ppx=px;%�f�[�^�i�[�p
        pv = v;
        ind=1;%�V����ID
        for ip=1:NP
            while(resampleID(ip)>wcum(ind))
                ind=ind+1;
            end
            px(1:end,ip)= [ppx(2:end,ind);ppx(end,ind)];%LVS�őI�΂ꂽ�p�[�e�B�N���ɒu������ppx(:,ind);%
            pv(1:end,ip)= [v(2:end,ind);v(end,ind)];%v(:,ind);%
            pw(ip)=1/NP;%�ޓx�͏�����
        end
%     elseif obj.Resamplingmode == "Date"
        
%     end
end

