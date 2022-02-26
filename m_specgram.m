function [yo, fo, to] = m_specgram(x, nfft, Fs, window, noverlap)
    nfft = round(nfft);
    nx = length(x);
    nwind = length(window);

    if nx < nwind % zero-pad x if it has length less than the window length
        x(nwind) = 0; nx = nwind;
    end

    x = x(:); % make a column vector for ease later
    window = window(:); % be consistent with data set

    ncol = fix((nx - noverlap) / (nwind - noverlap));
    colindex = 1 + (0:(ncol - 1)) * (nwind - noverlap);
    rowindex = (1:nwind)';

    if length(x) < (nwind + colindex(ncol) - 1)
        x(nwind + colindex(ncol) - 1) = 0; % zero-pad x
    end

    if length(nfft) > 1
        df = diff(nfft);
        evenly_spaced = all(abs(df - df(1)) / Fs < 1e-12); % evenly spaced flag (boolean)
        use_chirp = evenly_spaced & (length(nfft) > 20);
    else
        use_chirp = 0;
    end

    if (length(nfft) == 1) || use_chirp
        y = zeros(nwind, ncol);

        % put x into columns of y with the proper offset
        % should be able to do this with fancy indexing!
        y(:) = x(rowindex(:, ones(1, ncol)) + colindex(ones(nwind, 1), :) - 1);

        % Apply the window to the array of offset signal segments.
        y = window(:, ones(1, ncol)) .* y;

        if ~use_chirp % USE FFT
            % now fft y which does the columns
            y = fft(y, nfft);

            if ~any(any(imag(x))) % x purely real

                if mod(nfft, 2) ~= 0 % nfft odd
                    select = 1:(nfft + 1) / 2;
                else
                    select = 1:nfft / 2 + 1;
                end

                y = y(select, :);
            else
                select = 1:nfft;
            end

            f = (select - 1)' * Fs / nfft;
        else % USE CHIRP Z TRANSFORM
            f = nfft(:);
            f1 = f(1);
            f2 = f(end);
            m = length(f);
            w = exp(-1i * 2 * pi * (f2 - f1) / (m * Fs));
            a = exp(1i * 2 * pi * f1 / Fs);
            y = czt(y, m, w, a);
        end

    else % evaluate DFT on given set of frequencies
        f = nfft(:);
        q = nwind - noverlap;
        extras = floor(nwind / q);
        x = [zeros(q - rem(nwind, q) + 1, 1); x];
        % create windowed DTFT matrix (filter bank)
        D = window(:, ones(1, length(f))) .* exp((-1i * 2 * pi / Fs * ((nwind - 1):-1:0)).' * f');
        y = upfirdn(x, D, 1, q).';
        y(:, [1:extras + 1 end - extras + 1:end]) = [];
    end

    t = (colindex - 1)' / Fs;

    % take abs, and use image to display results
    if nargout == 1
        yo = y;
    elseif nargout == 2
        yo = y;
        fo = f;
    elseif nargout == 3
        yo = y;
        fo = f;
        to = t;
    end

end
