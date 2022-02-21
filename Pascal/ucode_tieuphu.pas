type ar = array[0..10000000] of longint;
var i,j,n,d:longint;
    x,h:ar;
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
    var i,j,m:longint;
    /////////////////
    begin
    i := l;
    j := r;
    m := a[(i + j) div 2];
    while (i <= j) do
        begin
        while (a[i] < m) do 
            i := i + 1;
        while (a[j] > m) do
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
assign(input,'ucode_tieuphu.inp');reset(input);
readln(n);
for i := 1 to n do
    readln(x[i],h[i]);
qsort(x,h,1,n);
//for i := 1 to n do
//    write(x[i],' ');
//writeln();
//for i := 1 to n do
//    write(h[i],' ');
//writeln();
d := 2;
for i := 2 to (n - 1) do
    begin
    if (x[i] - h[i] > x[i - 1]) then
        begin
        d := d + 1;
        //writeln('chopped left at ',x[i],', count is now ',d);
        end
    else if (x[i] + h[i] < x[i + 1]) then
        begin
        d := d + 1;
        //write('left at ',x[i],', count is now ',d);
        x[i] := x[i] + h[i];
        //writeln(', x[i] is now ',x[i]);
        end;
    end;
writeln(d);
end.