%% 只接受1分钟长度的音频，多的截去，少的补0
% x(inf,1) fs(1,1) w_starts(inf,1) w_ends(inf,1)
function [w_starts, w_ends] = vad(x, fs)

    %% -------------------音频最小长度60秒---------------------------
    MIN_LEN = 60 * fs;

    if (length(x) > MIN_LEN)
        x = x(1:MIN_LEN);
    end

    if (length(x) < MIN_LEN)
        x = [x; zeros(MIN_LEN - length(x), 1)];
    end

    maxs = amax_group(x, 50);
    sums = sum_group(maxs, 50);
    sums = median_filter(sums, 10);

    [bins, ~] = hist(sums, 200);
    [~, position] = max(bins);
    bins = sort(bins);
    tis = bins(end) / bins(end - 1);
    sorted_sums = sort(sums);
    %前60%的平均值
    ddth = mean(sorted_sums(1:fix(length(sorted_sums) * 0.6)));

    %取阈值？
    dth = vad_threshold(tis, sorted_sums, position);

    coder.varsize('w_starts');
    coder.varsize('w_ends');

    if max(sorted_sums) >= ddth * 5
        [nx1, nx2] = vad_below_threshold(sums, dth, 6);
        [nx3, nx4] = vad_wave(sums, nx1, nx2);
        % 映射至实际区间
        w_starts = (nx3 - 1) * 2500 + 1;
        w_ends = nx4 * 2500;
    else
        w_starts = zeros(0,1,'int64');
        w_ends = zeros(0,1,'int64');
    end

    %截取段过滤
    [w_starts, w_ends] = vad_length_filter(w_starts, w_ends, 0.03 * fs, 5 * fs);

end
