% 線形インデックスを作成
a=rand(5,5);
B=double(a>0.6)+1

A=zeros(4,4,2)
A(1:2,:,1)=[1,1,1,1;
    2,2,2,2];
A(1:2,:,2)=[3,3,3,3
    4,4,4,4];

[m, n, k] = size(A);
[p, q] = size(B);

% Bを1列ベクトルに変換
Bvec = B(:); % [p*q, 1]

% Aの各スライスを2次元に展開
A2 = reshape(A, m*n, k); % [m*n, k]

% BvecでA2から列を抽出
C2 = A2(:, Bvec); % [m*n, p*q]

% 元の形に戻す
C = reshape(C2, m, n, p, q); % [m, n, p, q]


D=zeros(4,4,5,5);
for i=1:size(B,1)
    for j=1:size(B,2)
        D(:,:,i,j)=A(:,:,B(i,j));
    end
end

%%
% プロジェクトAから、プロジェクトBを開く
currentProject = matlab.project.currentProject;
if ~isempty(currentProject)
    % 現在のプロジェクト情報を保存
    projectAPath = currentProject.RootFolder;
    % プロジェクトBを開く
    openProject('src/Contoroller/EvaluationPath_vec.prj');
    % ここでプロジェクトBの機能を使用
    % ...
    % 必要に応じて元のプロジェクトに戻る
    openProject(projectAPath);
end
%%
% A=rand(1,2,3,3)*rand(1,1)*-10;
% B=rand(1,2,3,3)*rand(1,1)*20;
C=rand(1,2,3,3)*rand(1,1)*3;
A=[0,5]
B=[0,9]
% C(:,:,3,3)=[1,6]
distance = get_distance(A, B, C);
figure
for i=1:size(distance,3)
    for j=1:size(distance,4)
        color=rand(1,3);
        % plot([A(1,1,i,j),B(1,1,i,j)],[A(1,2,i,j),B(1,2,i,j)],'Color',color)
        
        hold on
        viscircles(C(1,:,i,j), distance(:,:,i,j), 'Color', color)
        hold on
    end
end
axis equal
grid on
