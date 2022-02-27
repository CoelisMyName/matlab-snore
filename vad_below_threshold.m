%% 获取高于阈值的段 x数组，dth阈值，width宽度
function [ostarts, oends] = vad_below_threshold(xn, dth, width)
    bufferHeight = ceil(length(xn) / width) + 1;
    ostarts = zeros(bufferHeight, 1, 'int64');
    oends = zeros(bufferHeight, 1, 'int64');
    len = int64(0);
    count = 0;
    coder.varsize('ostarts');
    coder.varsize('oends');

    for i = 1:length(xn)

        if xn(i) > dth
            count = count + 1;
        end

        if xn(i) <= dth && count >= width
            len = len + 1;
            ostarts(len) = i - count;
            oends(len) = i - 1;
        end

        if xn(i) <= dth
            count = 0;
        end

    end

    % 到末尾，有声段可能大于
    if count >= width
        len = len + 1;
        ostarts(len) = length(xn) - count + 1;
        oends(len) = length(xn);
    end

    ostarts = ostarts(1:len);
    oends = oends(1:len);
end
