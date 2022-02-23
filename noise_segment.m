% 输入有声片段数组，返回无声段起点（秒）和长度（秒），-1则找不到符合的无声段
function [n_start, n_length] = noise_segment(w_starts, w_ends, fs, min_gap, margin)
    len = min(length(w_starts), length(w_ends));
    n_start = -1;
    n_length = -1;

    for i = 1:len - 1

        if w_starts(i + 1) - w_ends(i) > margin
            n_end = (w_starts(i + 1) - min_gap) / fs;
            n_start = (w_ends(i) + min_gap) / fs;
            n_length = n_end - n_start;
            break
        end

    end

end
