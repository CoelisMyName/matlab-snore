%给定宽度求和
function [result] = sum_group(array, width)
    result = zeros(floor(length(array) / width), 1);

    for i = 1:length(result)
        result(i) = sum(array((i - 1) * width + 1:i * width));
    end

end
