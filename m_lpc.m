function [a, e] = m_lpc(x, N)
    [m, n] = size(x);

    if (n > 1) && (m == 1)
        x = x(:);
        [m, ~] = size(x);
    end

    X = fft(x, 2^nextpow2(2 * size(x, 1) - 1));
    R = ifft(abs(X).^2);
    R = R ./ m; % Biased autocorrelation estimate

    [a, e] = levinson(R, N);

    a = real(a);

end
