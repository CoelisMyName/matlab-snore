function [SE_mean, SE_max, SE_min, SE_var] = se_feat(sig, fs)
    wlen = fix(0.02 * fs);
    inc = fix(0.5 * wlen);
    SE = zeros(1, ceil(length(sig) / inc));
    switch fs
        case 8000
            SE = spectralEntropy(sig, 8000, 'Window', hanning(160), 'OverlapLength', 80);
        case 11025
            SE = spectralEntropy(sig, 11025, 'Window', hanning(221), 'OverlapLength', 110);
        case 12000
            SE = spectralEntropy(sig, 12000, 'Window', hanning(240), 'OverlapLength', 120);
        case 22050
            SE = spectralEntropy(sig, 22050, 'Window', hanning(441), 'OverlapLength', 221);
        case 24000
            SE = spectralEntropy(sig, 24000, 'Window', hanning(480), 'OverlapLength', 240);
        case 44100
            SE = spectralEntropy(sig, 44100, 'Window', hanning(882), 'OverlapLength', 441);
        case 48000
            SE = spectralEntropy(sig, 48000, 'Window', hanning(960), 'OverlapLength', 480);
    end
    SE_mean = mean(SE(:));
    SE_max = max(SE(:));
    SE_min = min(SE(:));
    SE_var = var(SE(:));
end