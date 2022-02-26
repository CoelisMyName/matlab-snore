function MFCC_feature = mfcc_feat(sig, fs)
    [coeffs, delta, deltaDelta, ~] = mfcc(sig, fs, 'LogEnergy', 'Replace');
    coeffs_ = mean(coeffs);
    delta_ = mean(delta);
    deltaDelta_ = mean(deltaDelta);
    MFCC_feature = [coeffs_, delta_, deltaDelta_];
end