function pianyi = yuzhiSpeci(d, position)
    up = (max(d) - min(d)) / 200 * position + min(d);
    down = (max(d) - min(d)) / 200 * (position - 1) + min(d);
    dn = sort(d);
    ddn = dn(dn <= up);
    ddn = ddn(ddn > down);
    [ddnn, ~] = histcounts(ddn, 20);
    [~, ddmp] = max(ddnn);
    ddnns = sort(ddnn);
    m = ddnns(end) / ddnns(end - 1);

    if ddmp > 15
        pianyi = max(ddnns);
    elseif m >= 20
        pianyi = (max(ddnns) - min(ddnns)) / 20 * (ddmp + 4) + min(ddnns);
    elseif m > 10
        pianyi = (max(ddnns) - min(ddnns)) / 20 * (ddmp + 5) + min(ddnns);
    else
        pianyi = max(ddnns);
    end

end
