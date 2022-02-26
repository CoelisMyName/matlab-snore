function barkee = bark_feat(sig, fs)
    [BARK1, ~, ~] = BARKenergy(sig, fs);
    barkee = BARK1';
end