type ar = array[1..1000000] of longint;
var a:ar;
    i,x,n,l,r,test,tests:longint;
//////////////////////////////////////
procedure qsort(var a:ar;l,r:longint);
var i,j,x,tg:longint;
    begin
    i := l;
    j := r;
    x := a[(l + r) div 2];
    while (i <= j) do
        begin
        while (a[i] < x) do
            i := i + 1;
        while (a[j] > x) do
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
function notinx(a:ar;l,r,x:longint):string;
    /////////////////
    begin
    qsort(a,l,r);
    if ((a[l] <> x) or (a[r] <> x)) then
        exit('YES')
    else
        exit('NO');
    end;
///////////////////////////////////////
begin
assign(input,'ucode_phantukhacx.inp');reset(input);
readln(n,tests);
for i := 1 to n do
    read(a[i]);
for test := 1 to tests do
    begin
    readln(l,r,x);
    writeln(notinx(a,l,r,x));
    end;
end.