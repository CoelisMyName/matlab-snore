%给定宽度内绝对值最大值
function [result] = amax_group(array, width)
    result = zeros(1, floor(length(array) / width));

    for i = 1:length(result)
        result(i) = max(abs(array((i - 1) * width + 1:i * width)));
    end

end
