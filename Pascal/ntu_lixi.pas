type ar = array[0..10000000] of longint;
var i,j,n,d,t,mx:longint;
    a,b:ar;
///////////////////////////////////////
procedure swap(var a,b:longint);
    var tmp:longint;
    /////////////////
    begin
    tmp := a;
    a := b;
    b := tmp;
    end;
///////////////////////////////////////
procedure qsort(var a,b:ar;l,r:longint);
    var i,j,x,tg:longint;
    /////////////////
    begin
    i := l;
    j := r;
    x := a[(i + j) div 2];
    while (i <= j) do
        begin
        while (a[i] > x) do 
            i := i + 1;
        while (a[j] < x) do
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
        qsort(a,b,i,r);
    if (j > l) then
        qsort(a,b,l,j);
    end;
///////////////////////////////////////
begin
assign(input,'ntu_lixi.inp');reset(input);
readln(n);
for i := 1 to n do
    readln(a[i],b[i]);
qsort(b,a,1,n);
for i := 1 to n do
    begin
    //writeln(a[i]);
    end;
d := 1;
t := 0;
for i := 1 to n do
    begin
    //writeln('d ',d);
    //writeln('bi ',b[i]);
    if (d = 0) then
        break;
    d := d + b[i] - 1;
    t := t + a[i];
    if ((b[i + 1] = 0) and (b[i] <> 0)) then
        qsort(a,b,i + 1,n);
    //writeln(t);
    end;
writeln(t);
end.