type intar = array[0..1000000] of int64;
var a:intar;
    i,n:longint;
///////////////////////////////////////
procedure sort(var a:intar;l,r:longint);
    var m,i,j,tmp:longint;
    /////////////////
    begin
    i := l;
    j := r;
    m := a[(l + r) div 2];
    while (i <= j) do
        begin
        while (a[i] < m) do
            i := i + 1;
        while (a[j] > m) do
            j := j - 1;
        if (i <= j) then
            begin
            tmp := a[i];
            a[i] := a[j];
            a[j] := tmp;
            i := i + 1;
            j := j - 1;
            end;
        end;
    if (i < r) then
        sort(a,i,r);
    if (j > l) then
        sort(a,l,j);
    end;
///////////////////////////////////////
begin

end.