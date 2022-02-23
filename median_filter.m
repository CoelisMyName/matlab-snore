function [output] = median_filter(array, window)
    len = length(array);
    output = zeros(1, len);
    temp = zeros(1, window);
    lm = -floor(window / 2);
    rm = floor((window - 1) / 2);

    for i = 1:len

        for j = lm:rm
            index = i + j;
            tindex = j - lm + 1;

            if index < 1
                temp(tindex) = 0;
            elseif index > len
                temp(tindex) = 0;
            else
                temp(tindex) = array(index);
            end

        end

        output(i) = median(temp);
    end

end
