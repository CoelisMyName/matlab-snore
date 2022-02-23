function [p, f, s] = cweight(x)
    [p, f] = octbank(x, 44100);
    weight = [-0.8 -0.2 0 0 0 -0.2 -0.8 -3.0];
    p = p + weight;
    a = 10.^(0.1 * (p));
    s = 10 * log10(sum(a));
end
