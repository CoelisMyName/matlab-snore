% 输入有声片段数组，返回无声段起点（秒）和长度（秒），-1则找不到符合的无声段
function [ostart, olength] = noise_segment(w_starts, w_ends, fs, min_gap, margin)
    len = min(length(w_starts), length(w_ends));
    ostart = -1.0;
    olength = -1.0;

    for i = 1:len - 1

        if w_starts(i + 1) - w_ends(i) > margin
            oend = (double(w_starts(i + 1)) - min_gap) / fs;
            ostart = (double(w_ends(i)) + min_gap) / fs;
            olength = oend - ostart;
            break
        end

    end

end
