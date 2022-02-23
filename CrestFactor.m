function [CF_mean] = CrestFactor(x, fs)

    wlen = fix(0.02 * fs);
    wnd = hamming(wlen);
    inc = fix(0.5 * wlen);
    y = v_enframe(x, wnd, inc)';
    fn = size(y, 2);
    Crest_Factor = zeros(1, fn);

    for i = 1:fn
        YY = y(:, i); %取一帧数据
        V90th = sort(abs(YY)); %从小到大排列
        V90 = max(V90th(1:end - floor(length(V90th) * 0.1))); %前90 %d的最大值
        V10th = V90th(floor(length(V90th) * 0.1):end - floor(length(V90th) * 0.1)); % 10 %到90 %之间的值
        Vrms = rms(V10th);
        Crest_Factor(i) = V90 / Vrms;
    end

    CF_mean = mean(Crest_Factor);
end
