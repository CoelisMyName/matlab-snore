function [p, f, s] = aweight(x)
    [p, f] = octbank(x, 44100);
    weight = [-26.2 -16.1 -8.6 -3.2 0 1.2 1.0 -1.1];
    p = p + weight;
    a = 10.^(0.1 * (p));
    s = 10 * log10(sum(a));
end
