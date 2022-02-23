function [PR800_mean, PR800_max, PR800_min, PR800_var] = PR800(x, Fs)
    %UNTITLED4 此处显示有关此函数的摘要
    %   此处显示详细说明
    wlen = fix(0.02 * Fs);
    inc = fix(0.5 * wlen);
    wind = hamming(wlen);
    y = v_enframe(x, wind, inc)';
    fn = size(y, 2); %总帧数
    PR800 = zeros(1, fn);
    ds = Fs / wlen;
    f1 = 800 / ds + 1;
    f2 = 8000 / ds + 1;

    for i = 1:fn
        YY = y(:, i); %取一帧数据
        n = 0:length(YY) - 1;
        Z = fft(YY);
        f = n * Fs / length(YY);
        mag = abs(Z);
        PR800(i) = log10(sum(mag(1:f1) .* mag(1:f1)) / sum(mag(f1:f2) .* mag(f1:f2)));
    end

    % for i = 1:fn
    %     YY = y(:,i);  %取一帧数据
    %     n = 0:length(YY)-1;
    %     Z=fft(YY);
    %     f=n*Fs/length(YY);
    %     mag=abs(Z);
    %     PR800(i)=log10(sum(mag(1:17).*mag(1:17))/sum(mag(17:161).*mag(17:161)));
    % end
    PR800_mean = mean(PR800);
    PR800_max = max(PR800);
    PR800_min = min(PR800);
    PR800_var = var(PR800);
end
