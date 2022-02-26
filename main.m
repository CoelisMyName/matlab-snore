[sig,fs] = audioread('../2022-02-24-21-23-01-538.wav');
MFCC_feature = mfcc_feat(sig,fs)
BARKEE = bark_feat(sig,fs)
[period_mean, period_max, period_min, period_var] = pitch_feat(sig,fs)
cep = cep_feat(sig,fs)
[Formant1, Formant2, Formant3] = fmt_feat(sig,fs)
GTCCmean = gtcc_feat(sig,fs)
[PR800mean, PR800max, PR800min, PR800var] = pr800_feat(sig,fs)
[SE_mean, SE_max, SE_min, SE_var] = se_feat(sig,fs)
label_OSA = patient_classifier(MFCC_feature, BARKEE, period_mean, period_max, period_min, period_var,...
    cep, Formant1, Formant2, Formant3, GTCCmean, PR800mean, PR800max, PR800min, PR800var,...
    SE_mean, SE_max, SE_min, SE_var)