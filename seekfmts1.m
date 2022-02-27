function [fmt] = seekfmts1(sig, Nt, fs, Nlpc)
    % fmt:3*Nt的数组
    %sig 输入声音信号
    %Nt分帧后的总帧数
    %fs采样频率
    %Nlpc：lpc分析的阶数
    if nargin < 4, Nlpc = round(fs / 1000) + 2; end
    Nt = round(Nt);
    ls = length(sig); % 数据长度
    Nwin = floor(ls / Nt); % 帧长

    fmt = zeros(3, Nt);

    for m = 1:Nt
        lpcsig = sig((Nwin * (m - 1) + 1):min([(Nwin * m) ls])); % 取来一帧信号
        a = m_lpc(lpcsig, Nlpc); % 计算LPC系数
        const = fs / (2 * pi); % 常数
        rts = roots(a(:)); % 求根
        k = 1; % 初始化
        yf = [];
        bandw = [];
        coder.varsize('yf');
        coder.varsize('bandw');

        for i = 1:length(a) - 1
            re = real(rts(i)); % 取根之实部
            im = imag(rts(i)); % 取根之虚部
            formn = const * atan2(im, re); % 计算共振峰频率
            bw = -2 * const * log(abs(rts(i))); % 计算带宽

            if formn > 150 && bw < 700 && formn < fs / 2 % 满足条件方能成共振峰和带宽
                yf = [yf formn];
                bandw = [bandw, bw];
                k = k + 1;
            end

        end

        [y, ind] = sort(yf); % 排序
        bw = bandw(ind);
        F = [NaN NaN NaN]; % 初始化
        F(1:min(3, length(y))) = y(1:min(3, length(y))); % 输出最多三个
        F = F(:); % 按列输出
        fmt(:, m) = F / (fs / 2); % 归一化频率

    end

end
