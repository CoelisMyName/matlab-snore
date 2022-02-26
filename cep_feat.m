function cep = cep_feat(sig, fs)
    %plp特征+一阶差分+二阶差分合集39阶特征
    [cep2, ~] = rastaplp(sig, fs, 0, 12);
    del = deltas(cep2);
    ddel = deltas(deltas(cep2, 5), 5);
    cepDpDD = [cep2; del; ddel];
    cep1 = mean(cepDpDD, 2); %取均值
    cep = cep1';
end