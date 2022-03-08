% 读取音频数据
[x, fs] = audioread('1min.wav');
% [x, fs] = audioread('20131025刘俊光1min降噪.wav');
xn = x;
n_start = 0;
n_length = 1;
% libsox 降噪
% sox $x -n trim $n_start $n_length noiseprof noise.txt
% sox $x $xn noised noise.txt
% 端点检测和截取
[w_starts, w_ends] = vad(xn, fs);
[n_start, n_length] = noise_segment(w_starts, w_ends, fs, 0.5 * fs, 3 * fs);

if n_start >= 0
    % 更新降噪
    % sox $x -n trim $n_start $n_length noiseprof noise.txt
end

% 模型分类
predict_label = classifier(xn, fs, w_starts, w_ends);
