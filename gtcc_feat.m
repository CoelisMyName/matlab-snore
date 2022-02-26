function GTCCmean = gtcc_feat(sig, fs)
    coeffs = zeros(max(ceil(length(sig) / (0.01 * fs)),20), 20);
    switch fs
        case 8000
            [coeffs, ~, ~, ~] = gtcc(sig, 8000, 'NumCoeffs', 20,'Window', hann(160),...
            'OverlapLength', 80, 'LogEnergy', 'Replace','FilterDomain', 'Time');
        case 11025
            [coeffs, ~, ~, ~] = gtcc(sig, 11025, 'NumCoeffs', 20,'Window', hann(221),...
                'OverlapLength', 110,'LogEnergy', 'Replace','FilterDomain', 'Time');
        case 12000
            [coeffs, ~, ~, ~] = gtcc(sig, 12000, 'NumCoeffs', 20,'Window', hann(240),...
                'OverlapLength', 120,'LogEnergy', 'Replace','FilterDomain', 'Time');
        case 22050
            [coeffs, ~, ~, ~] = gtcc(sig, 22050, 'NumCoeffs', 20,'Window', hann(441),...
                'OverlapLength', 221,'LogEnergy', 'Replace','FilterDomain', 'Time');
        case 24000
            [coeffs, ~, ~, ~] = gtcc(sig, 24000, 'NumCoeffs', 20,'Window', hann(480),...
                'OverlapLength', 240,'LogEnergy', 'Replace','FilterDomain', 'Time');
        case 44100
            [coeffs, ~, ~, ~] = gtcc(sig, 44100, 'NumCoeffs', 20,'Window', hann(882),...
                'OverlapLength', 441,'LogEnergy', 'Replace','FilterDomain', 'Time');
        case 48000
            [coeffs, ~, ~, ~] = gtcc(sig, 48000, 'NumCoeffs', 20,'Window', hann(960),...
                'OverlapLength', 480,'LogEnergy', 'Replace','FilterDomain', 'Time');
    end
    GTCCmean = mean(coeffs);
end
