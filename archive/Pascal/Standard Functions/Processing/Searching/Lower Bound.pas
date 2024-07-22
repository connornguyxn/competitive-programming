function lower_bound(n,l,r:longint;a:ar):boolean;
    var m:longint;
    /////////////////
    begin
    lower_bound := -1;
    while (l <= r) do
        begin
        m := (l + r) div 2;
        if (n < a[m]) then
            r := m - 1
        else if (n > a[m]) then
            l := m + 1
        else
            begin
            lower_bound := m;
            r := m - 1;
            end;
        end;
    end;