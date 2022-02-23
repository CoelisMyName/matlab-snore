%% 按波形重新分段
function [w_starts, w_ends] = vad_wave(array, s_starts, s_ends)
w_starts = zeros(1, length(s_starts));
w_ends = zeros(1, length(s_ends));
coder.varsize('w_starts');
coder.varsize('w_ends');
k = 1;

for i = 1:min(length(s_starts), length(s_ends))
    if(k > length(w_ends))
        w_ends = [w_ends zeros(1, k)];
        w_starts = [w_starts zeros(1, k)];
    end
    w_starts(k) = s_starts(i);
    islow = 0;
    count = 0;
    lowb = -1;
    
    for j = s_starts(i) + 1:s_ends(i)
        
        if array(j) - array(j - 1) < -0.01
            islow = 1;
        end
        
        if islow == 1 && abs(array(j) - array(j - 1)) <= 0.01
            count = count + 1;
            
            if (lowb == -1)
                lowb = j;
            end
            
        elseif islow == 1
            %连续下降的特殊情况
            if array(j) < array(j - 1)
                %后一个点抬升
                if (j + 1 < s_ends(i) && array(j + 1) - array(j) <= 0.01)
                    lowb = j; %j+1; %lowb针对连续下降不断往后推，直到碰到抬升点，lowb记录的是最后一个非上升点，波谷的前一个点
                end
                
            else
                
                if (count >= 3)
                    if(k > length(w_ends))
                        w_ends = [w_ends zeros(1, k)];
                        w_starts = [w_starts zeros(1, k)];
                    end
                    w_ends(k) = lowb;
                    k = k + 1;
                    if(k > length(w_ends))
                        w_ends = [w_ends zeros(1, k)];
                        w_starts = [w_starts zeros(1, k)];
                    end
                    w_starts(k) = j - 1;
                    islow = 0;
                    lowb = -1;
                end
                
                count = 0;
            end
            
        end
        
    end
    if(k > length(w_ends))
        w_ends = [w_ends zeros(1, k)];
        w_starts = [w_starts zeros(1, k)];
    end
    w_ends(k) = s_ends(i);
    k = k + 1;
    
end

w_starts = w_starts(1:k - 1);
w_ends = w_ends(1:k - 1);
end
