function [fmt1_mean, fmt2_mean, fmt3_mean] = formantfeature(x, Fs)
    %提取共振峰特征
    wlen = fix(0.02 * Fs);
    wind = hanning(wlen);
    inc = fix(0.5 * wlen);
    y = enframe(x, wind, inc)';
    fn = size(y, 2);
    fmt = seekfmts1(x, fn, Fs, 10);
    fmt1 = (fmt(1, :)) * (Fs / 2);
    fmt2 = (fmt(2, :)) * (Fs / 2);
    fmt3 = (fmt(3, :)) * (Fs / 2);
    fmt1_mean = nanmean(fmt1);
    fmt2_mean = nanmean(fmt2);
    fmt3_mean = nanmean(fmt3);

    if isnan(fmt1_mean)
        fmt1_mean = 0;
    end

    if isnan(fmt2_mean)
        fmt2_mean = 0;
    end

    if isnan(fmt3_mean)
        fmt3_mean = 0;
    end

end
