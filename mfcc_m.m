function ccc = mfcc_m(x, fs, p, frameSize, inc)
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %    function ccc=mfcc_m(x,fs,p,frameSize,inc)
    %���������������x����MFCC��������ȡ������MFCC������һ��
    %���MFCC������Mel�˲����ĸ���Ϊp������Ƶ��Ϊfs
    %��xÿframeSize���Ϊһ֡��������֮֡���֡��Ϊinc
    % FFT�ĳ���Ϊ֡��
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    % ��֡��ΪframeSize��Mel�˲����ĸ���Ϊp������Ƶ��Ϊfs
    % ��ȡMel�˲����������ú���������
    bank = melbankm(p, frameSize, fs, 0, 0.5, 'm');
    % ��һ��Mel�˲�����ϵ��
    bank = full(bank);
    bank = bank / max(bank(:));
    p2 = p / 2;
    % DCTϵ��,p2*p
    dctcoef = zeros(p2, p);

    for k = 1:p2
        n = 0:p - 1;
        dctcoef(k, :) = cos((2 * n + 1) * k * pi / (2 * p));
    end

    % ��һ��������������
    w = 1 + 6 * sin(pi * [1:p2] ./ p2);
    w = w / max(w);

    % Ԥ�����˲���
    xx = double(x);
    xx = filter([1 -0.9375], 1, xx);

    % �����źŷ�֡
    xx = v_enframe(xx, frameSize, inc);
    n2 = fix(frameSize / 2) + 1;
    % ����ÿ֡��MFCC����
    fn = size(xx, 1);
    m = zeros(fn, p2);

    for i = 1:size(xx, 1)
        y = xx(i, :);
        s = y' .* hamming(frameSize);
        t = abs(fft(s));
        t = t.^2;
        c1 = dctcoef * log(bank * t(1:n2));
        c2 = c1 .* w';
        m(i, :) = c2';
    end

    %���ϵ��
    dtm = zeros(size(m));

    for i = 3:size(m, 1) - 2
        dtm(i, :) = -2 * m(i - 2, :) - m(i - 1, :) + m(i + 1, :) + 2 * m(i + 2, :);
    end

    dtm = dtm / 3;
    %�ϲ�MFCC������һ�ײ��MFCC����
    ccc = [m dtm];
    %ȥ����β��֡����Ϊ����֡��һ�ײ�ֲ���Ϊ0
    ccc = ccc(3:size(m, 1) - 2, :);
  end
