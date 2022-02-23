function [predict_label] = classifier(x, w_starts, w_ends, fs)
    N = min(length(w_starts), length(w_ends));

    period_mean = zeros(1, N);
    period_min = zeros(1, N);
    period_max = zeros(1, N);
    period_var = zeros(1, N);
    mfcc_new = zeros(16, N);
    Crest_Factor = zeros(1, N);
    HZCRR = zeros(1, N);
    Eh = zeros(1, N);
    BARKEE = zeros(17, N);
    LPCmean = zeros(12, N);
    PR800mean = zeros(1, N);
    PR800max = zeros(1, N);
    PR800min = zeros(1, N);
    PR800var = zeros(1, N);

    for i = 1:N
        wlen = fix(0.02 * fs);
        inc = fix(0.5 * wlen);
        sig = x(w_starts(i):w_ends(i))';
        sig = sig - mean(sig);
        sig = sig / max(abs(sig));
        sig1 = sig;

        [Eh1, ~] = HENR(sig1, fs);
        Eh(i) = Eh1;
        f0 = [];
        % 适配Coder
        switch fs
            case 8000
                f0 = pitch(sig1, 8000, 'WindowLength', 400, 'OverlapLength', 200);
            case 11025
                f0 = pitch(sig1, 11025, 'WindowLength', 551, 'OverlapLength', 276);
            case 12000
                f0 = pitch(sig1, 12000, 'WindowLength', 600, 'OverlapLength', 300);
            case 22050
                f0 = pitch(sig1, 22050, 'WindowLength', 1103, 'OverlapLength', 551);
            case 24000
                f0 = pitch(sig1, 24000, 'WindowLength', 1200, 'OverlapLength', 600);
            case 44100
                f0 = pitch(sig1, 44100, 'WindowLength', 2205, 'OverlapLength', 1103);
            case 48000
                f0 = pitch(sig1, 48000, 'WindowLength', 2400, 'OverlapLength', 1200);
        end
        
        period_mean(i) = mean(f0); %计算基音周期的平均值
        period_min(i) = min(f0); %计算基音周期的最小值
        period_max(i) = max(f0); %计算基音周期的最大值
        period_var(i) = var(f0); %计算基音周期的方差

        [vzc, ~] = FeatureTimeZeroCrossingRate(sig1, wlen, inc, fs);
        zcr_m = 1.5 * mean(vzc);
        HZCRR(i) = sum(vzc > zcr_m) / length(vzc);

        framesize = fix(0.02 * fs); %帧长20ms，帧移0.25 使用这个
        inc = fix(0.25 * framesize);
        ccc1 = mfcc_m(sig1, fs, 16, framesize, inc); %sig1
        ccc = mean(ccc1)'; %sig1
        mfcc_new(:, i) = ccc;

        [CF_mean] = CrestFactor(sig1, fs); %sig1
        Crest_Factor(i) = CF_mean;

        [BARK1, ~, ~] = BARKenergy(sig1, fs); %
        % BARKse(:,i) =BPSE1;
        BARKEE(:, i) = BARK1;
        %----------------------提取LPC特征----------------------------
        [~, LPC_mean, ~, ~, ~] = LPCFeature(sig1, fs);
        LPCmean(:, i) = LPC_mean';
        % %---------------------PR800-----------------------------------
        [PR800_mean, PR800_max, PR800_min, PR800_var] = PR800(sig1, fs);
        PR800mean(i) = PR800_mean;
        PR800max(i) = PR800_max;
        PR800min(i) = PR800_min;
        PR800var(i) = PR800_var;
    end

    feature1 = [mfcc_new', BARKEE', LPCmean', period_mean', period_min', period_max', period_var', Crest_Factor', HZCRR', Eh', PR800mean', PR800max', PR800min', PR800var'];

    feature = feature1(:, [3, 18, 19, 1, 46, 47, 53, 34, 50, 30, 31, 51, 33, 42, 54, 29, 28, 32, 53, 7, 52, 27, 36]);
    my_model = loadLearnerForCoder('compacted_model');
    predict_label = predict(my_model, feature)';
end
