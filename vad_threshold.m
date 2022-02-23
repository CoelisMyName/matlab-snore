%阈值生成
function [dth] = vad_threshold(tis, sorted_sums, position)

    if tis > 50
        dth = yuzhiSpeci(sorted_sums, position);
    elseif tis > 20
        dth = ((max(sorted_sums) - min(sorted_sums)) / 200) * (position + 1.5) + min(sorted_sums);
    elseif tis > 7
        dth = ((max(sorted_sums) - min(sorted_sums)) / 200) * (-1/13 * tis + 20/13 + position + 2.5) + min(sorted_sums);
    elseif tis > 2
        dth = ((max(sorted_sums) - min(sorted_sums)) / 200) * (position + (-0.6 * tis + 5.2) + 2.5) + min(sorted_sums);
    else
        dth = ((max(sorted_sums) - min(sorted_sums)) / 200) * (position + 6.5) + min(sorted_sums);
    end

end
