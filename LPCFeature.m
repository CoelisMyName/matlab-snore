function [LPC, LPC_mean, LPC_max, LPC_min, LPC_var] = LPCFeature(x, Fs)
    %UNTITLED2 此处显示有关此函数的摘要
    %   此处显示详细说明
    wlen = fix(0.02 * Fs);
    inc = fix(0.5 * wlen);
    wind = hamming(wlen);
    y = enframe(x, wind, inc)'; %分帧
    fn = size(y, 2); %总帧数
    LPC = zeros(13, fn);

    for i = 1:fn
        YY = y(:, i); %取一帧数据
        z_new = filter([1 -0.99], 1, YY); %预加重
        LPC(:, i) = m_lpc(z_new, 12);
    end

    LPC = LPC'; %每一行有13个系数
    LPC = LPC(:, 2:13);
    LPC_mean = mean(LPC);
    LPC_max = max(LPC);
    LPC_min = min(LPC);
    LPC_var = var(LPC);
end
