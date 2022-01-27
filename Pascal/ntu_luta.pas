var i,n,d:longint;
    k:int64;
    a,b:array[0..100000000] of longint;
///////////////////////////////////////
procedure swap(var a1,b1:longint);
var tmp:qword;
    begin
    tmp := a1;
    a1 := b1;
    b1 := tmp;
    end;
/////////////////
procedure qsort(l,r:longint);
var i,j,x,tg:longint;
    begin
    i := l;
    j := r;
    x := a[(i + j) div 2];
    while (i <= j) do
        begin
        while (a[i] < x) do 
            i := i + 1;
        while (a[j] > x) do
            j := j - 1;
        if (i <= j) then
            begin
            swap(a[i],a[j]);
            swap(b[i],b[j]);
            i := i + 1;
            j := j - 1;
            end;
        end;
    if (i < r) then 
        qsort(i,r);
    if (j > l) then
        qsort(l,j);
    end;
///////////////////////////////////////
begin
assign(input,'ntu_luta.inp');reset(input);
readln(n,k);
for i := 1 to n do
    readln(a[i],b[i]);
qsort(1,n);
d := 0;
for i := 1 to n do
    begin
    if (a[i] <= k) then
        begin
        k := k + b[i];
        d := d + 1;
        end
    else
        break;
    end;
writeln(d);
end.