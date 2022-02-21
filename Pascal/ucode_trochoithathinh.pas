type ar = array[0..100000000] of longint;
var a:ar;
    i,n,m,k:longint;
    t:int64;
//////////////////////////////////////
procedure qsort(var a:ar;l,r:longint);
var i,j,x,tg:longint;
    begin
    i := l;
    j := r;
    x := a[(l + r) div 2];
    while (i <= j) do
        begin
        while (a[i] > x) do
            i := i + 1;
        while (a[j] < x) do
            j := j - 1;
        if (i <= j) then
            begin
            tg := a[i];
            a[i] := a[j];
            a[j] := tg;
            i := i + 1;
            j := j - 1;
            end;
        end;
    if (i < r) then
        qsort(a,i,r);
    if (j > l) then
        qsort(a,l,j);
    end;
///////////////////////////////////////
begin
assign(input,'ucode_trochoithathinh.inp');reset(input);
readln(n,m,k);
for i := 1 to n do
    read(a[i]);
qsort(a,1,n);
t := a[1] * (m div (k + 1)) * k;
t := t + m mod (k + 1);
t := t + a[2] * m div (k + 1);
writeln(t);
end.