%% 按波形重新分段
function [ostarts, oends] = vad_wave(array, starts, ends)
    tstarts = zeros(1, length(starts), 'int64');
    tends = zeros(1, length(ends), 'int64');
    coder.varsize('tstarts');
    coder.varsize('tends');
    k = 1;

    for i = 1:min(length(starts), length(ends))

        if (k > length(tends))
            tends = [tends zeros(1, k, 'int64')];
            tstarts = [tstarts zeros(1, k, 'int64')];
        end

        tstarts(k) = starts(i);
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

                        if (k > length(tends))
                            tends = [tends zeros(1, k, 'int64')];
                            tstarts = [tstarts zeros(1, k, 'int64')];
                        end

                        tends(k) = lowb;
                        k = k + 1;

                        if (k > length(tends))
                            tends = [tends zeros(1, k, 'int64')];
                            tstarts = [tstarts zeros(1, k, 'int64')];
                        end

                        tstarts(k) = j - 1;
                        islow = 0;
                        lowb = int64(-1);
                    end

                    count = 0;
                end

            end

        end

        if (k > length(tends))
            tends = [tends zeros(1, k, 'int64')];
            tstarts = [tstarts zeros(1, k, 'int64')];
        end

        tends(k) = ends(i);
        k = k + 1;

    end

    ostarts = tstarts(1:k - 1)';
    oends = tends(1:k - 1)';
end
