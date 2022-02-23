%%vad_length_filter: stars 开始 ends 结束 min_len 最小长度 max_len 最大长度
function [fstarts, fends] = vad_length_filter(starts, ends, min_len, max_len)
    k = 0;
    fstarts = zeros(1, length(starts));
    fends = zeros(1, length(ends));
    coder.varsize('fstarts');
    coder.varsize('fends');

    for i = 1:min(length(starts), length(ends))
        len = ends(i) - starts(i) + 1;
% 小于限定长度或大于限定长度的都抛弃
        if len > min_len && len < max_len
            k = k + 1;
            fstarts(k) = starts(i);
            fends(k) = ends(i);
        end

    end
% 对结果进行裁剪
    fstarts = fstarts(1:k);
    fends = fends(1:k);
end
