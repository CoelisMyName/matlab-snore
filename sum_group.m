%给定宽度求和
function [result] = sum_group(array, width)
    result = zeros(1, floor(length(array) / width));

    for i = 1:length(result)
        result(i) = sum(array((i - 1) * width + 1:i * width));
    end

end
