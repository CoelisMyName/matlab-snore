function label_OSA = patient_classifier(MFCC_feature, BARKEE, period_mean, period_max, period_min, period_var,...
    cep, Formant1, Formant2, Formant3, GTCCmean, PR800mean, PR800max, PR800min, PR800var,...
    SE_mean, SE_max, SE_min, SE_var)

    feature = [MFCC_feature, BARKEE, period_mean, period_max, period_min, period_var,...
        cep, Formant1, Formant2, Formant3, GTCCmean, PR800mean, PR800max, PR800min, PR800var,...
        SE_mean, SE_max, SE_min, SE_var];

    indexModel = coder.load('index.mat');

    feature_1 = feature(:, indexModel.index);
    
    threshold = -15; % 阈值 由实验得出
    model = coder.load('GMMmodel.mat');
    [label_OSA] = GMM_score(feature_1, model.speakerGmm, threshold);
end
