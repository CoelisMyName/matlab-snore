%% 按波形重新分段
function [ostarts, oends] = vad_wave(array, starts, ends)
    bufferHeight = min(length(starts), length(ends));
    ostarts = zeros(bufferHeight, 1, 'int64');
    oends = zeros(bufferHeight, 1, 'int64');
    coder.varsize('ostarts');
    coder.varsize('oends');
    k = int64(1);

    for i = 1:bufferHeight

        if (k > length(oends))
            ostarts = [ostarts; zeros(k, 1, 'int64')];
            oends = [oends; zeros(k, 1, 'int64')];
        end

        ostarts(k) = starts(i);
        islow = 0;
        count = 0;
        lowb = int64(-1);

        for j = starts(i) + 1:ends(i)

            if array(j) - array(j - 1) < -0.01
                islow = 1;
            end

            if islow == 1 && abs(array(j) - array(j - 1)) <= 0.01
                count = count + 1;

                if (lowb == int64(-1))
                    lowb = j;
                end

            elseif islow == 1
                %连续下降的特殊情况
                if array(j) < array(j - 1)
                    %后一个点抬升
                    if (j + 1 < ends(i) && array(j + 1) - array(j) <= 0.01)
                        lowb = j; %j+1; %lowb针对连续下降不断往后推，直到碰到抬升点，lowb记录的是最后一个非上升点，波谷的前一个点
                    end

                else

                    if (count >= 3)

                        if (k > length(oends))
                            ostarts = [ostarts; zeros(k, 1, 'int64')];
                            oends = [oends; zeros(k, 1, 'int64')];
                        end

                        oends(k) = lowb;
                        k = k + 1;

                        if (k > length(oends))
                            ostarts = [ostarts; zeros(k, 1, 'int64')];
                            oends = [oends; zeros(k, 1, 'int64')];
                        end

                        ostarts(k) = j - 1;
                        islow = 0;
                        lowb = int64(-1);
                    end

                    count = 0;
                end

            end

        end

        if (k > length(oends))
            ostarts = [ostarts; zeros(k, 1, 'int64')];
            oends = [oends; zeros(k, 1, 'int64')];
        end

        oends(k) = ends(i);
        k = k + 1;

    end

    ostarts = ostarts(1:k - 1);
    oends = oends(1:k - 1);
end
