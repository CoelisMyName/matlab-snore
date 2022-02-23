function [p, f, s] = zweight(x)
    [p, f] = octbank(x, 44100);
    a = 10.^(0.1 * (p));
    s = 10 * log10(sum(a));
end
