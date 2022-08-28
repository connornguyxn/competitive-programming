type ar = array[1..1000000] of longint;
///////////////////////////////////////
function search(k,l,r:longint;a:ar):longint;
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
            exit(m);
        end;
    exit(0);
    end;