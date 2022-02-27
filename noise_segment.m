% 输入有声片段数组，返回无声段起点（秒）和长度（秒），-1则找不到符合的无声段
function [ostart, olength] = noise_segment(starts, ends, fs, min_gap, margin)
    len = min(length(starts), length(ends));
    ostart = -1.0;
    olength = -1.0;

    for i = 1:len - 1

        if starts(i + 1) - ends(i) > margin
            oend = (double(starts(i + 1)) - min_gap) / fs;
            ostart = (double(ends(i)) + min_gap) / fs;
            olength = oend - ostart;
            break
        end

    end

end
