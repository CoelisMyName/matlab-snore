function [period_mean, period_min, period_max, period_var] = pitch_feat(sig, fs)
    f0 = [0];
    % 适配Coder
    switch fs
        case 8000
            f0 = pitch(sig, 8000, 'WindowLength', 400, 'OverlapLength', 200);
        case 11025
            f0 = pitch(sig, 11025, 'WindowLength', 551, 'OverlapLength', 276);
        case 12000
            f0 = pitch(sig, 12000, 'WindowLength', 600, 'OverlapLength', 300);
        case 22050
            f0 = pitch(sig, 22050, 'WindowLength', 1103, 'OverlapLength', 551);
        case 24000
            f0 = pitch(sig, 24000, 'WindowLength', 1200, 'OverlapLength', 600);
        case 44100
            f0 = pitch(sig, 44100, 'WindowLength', 2205, 'OverlapLength', 1103);
        case 48000
            f0 = pitch(sig, 48000, 'WindowLength', 2400, 'OverlapLength', 1200);
    end
    period_mean = mean(f0); %计算基音周期的平均值
    period_min = min(f0); %计算基音周期的最小值
    period_max = max(f0); %计算基音周期的最大值
    period_var = var(f0); %计算基音周期的方差
end
