function [Eh, En_mean] = HENR(x, fs)
    %高能量帧比率，计算一段声音信号中短时能量大于平均短时能量*0.5的比率
    % 输入x为信号，fs为采样率
    wlen = fix(0.02 * fs);
    inc = fix(0.5 * wlen);
    wnd = hanning(wlen);
    y = v_enframe(x, wnd, inc)';
    fn = size(y, 2);
    En = zeros(1, fn);

    for i = 1:fn
        Y = y(:, i);
        En(i) = Y' * Y;
    end

    En_mean = mean(En); %求取频率能量
    Eh = sum(En > (0.5 * En_mean)) / fn;

end
