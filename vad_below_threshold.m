%% 获取高于阈值的段 x数组，dth阈值，width宽度
function [starts, ends] = vad_below_threshold(xn, dth, width)
    starts = zeros(1, ceil(length(xn) / width));
    ends = zeros(1, ceil(length(xn) / width));
    len = 0;
    count = 0;
    coder.varsize('starts');
    coder.varsize('ends');

    for i = 1:length(xn)

        if xn(i) > dth
            count = count + 1;
        end

        if xn(i) <= dth && count >= width
            len = len + 1;
            starts(len) = i - count;
            ends(len) = i - 1;
        end

        if xn(i) <= dth
            count = 0;
        end

    end

    % 到末尾，有声段可能大于
    if count >= width
        len = len + 1;
        starts(len) = length(xn) - count + 1;
        ends(len) = length(xn);
    end

    starts = starts(1:len);
    ends = ends(1:len);
end
