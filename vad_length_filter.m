%%vad_length_filter: stars 开始 ends 结束 min_len 最小长度 max_len 最大长度
function [ostarts, oends] = vad_length_filter(starts, ends, min_len, max_len)
    k = 0;
    tstarts = zeros(1, length(starts), 'int64');
    tends = zeros(1, length(ends), 'int64');
    coder.varsize('tstarts');
    coder.varsize('tends');

    for i = 1:min(length(starts), length(ends))
        len = ends(i) - starts(i) + 1;
        % 小于限定长度或大于限定长度的都抛弃
        if len > min_len && len < max_len
            k = k + 1;
            tstarts(k) = starts(i);
            tends(k) = ends(i);
        end

    end

    % 对结果进行裁剪
    ostarts = tstarts(1:k)';
    oends = tends(1:k)';
end
