function binsearch(k,l,r:longint;a:ar):boolean;
    var m:longint;
    /////////////////
    begin
    while (l <= r) do
        begin
        m := (l + r) div 2;
        if (k < a[m]) then
            r := m - 1
        else if (k > a[m]) then
            l := m + 1
        else
            exit(true);
        end;
    exit(false);
    end;