function [label] = GMM_score(data_test, speakerGmm, threshold)
    n_class = 2;

    maxv = zeros(1,n_class);
    
    for i = 1:n_class
        mu_t = speakerGmm(i).mu;
        sigma_t = speakerGmm(i).sigm;
        c_t = speakerGmm(i).c;
        [~, lY] = lmultigauss(data_test', mu_t, sigma_t, c_t);
        maxv(i) = mean(lY);
    end

    match = maxv;

    if match(1) - match(2) < threshold %设置阈值
        label = 1;
    else
        label = 0;
    end

end
