function ccc = mfcc_m(x, fs, p, frameSize, inc)
    bank = melbankm(p, frameSize, fs, 0, 0.5, 'm');
    bank = full(bank);
    bank = bank / max(bank(:));
    p2 = p / 2;
    dctcoef = zeros(p2, p);

    for k = 1:p2
        n = 0:p - 1;
        dctcoef(k, :) = cos((2 * n + 1) * k * pi / (2 * p));
    end

    w = 1 + 6 * sin(pi * [1:p2] ./ p2);
    w = w / max(w);

    xx = double(x);
    xx = filter([1 -0.9375], 1, xx);

    xx = enframe(xx, frameSize, inc);
    n2 = fix(frameSize / 2) + 1;
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

    dtm = zeros(size(m));

    for i = 3:size(m, 1) - 2
        dtm(i, :) = -2 * m(i - 2, :) - m(i - 1, :) + m(i + 1, :) + 2 * m(i + 2, :);
    end

    dtm = dtm / 3;
    ccc = [m dtm];
    ccc = ccc(3:size(m, 1) - 2, :);
end
