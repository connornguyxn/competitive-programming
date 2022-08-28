type ar = array[0..10000000] of longint;
var i,j,n:longint;
    m:ansistring;
    x,y:ar;
    test:array[0..100000, 0..100000] of longint;
///////////////////////////////////////
procedure swap(var x,y:longint);
    var tmp:longint;
    /////////////////
    begin
    tmp := x;
    x := y;
    y := tmp;
    end;
///////////////////////////////////////
procedure qsort(var x,y:ar;l,r:longint);
    var i,j,m,tg:longint;
    /////////////////
    begin
    i := l;
    j := r;
    m := x[(i + j) div 2];
    while (i <= j) do
        begin
        while (x[i] > m) do 
            i := i + 1;
        while (x[j] < m) do
            j := j - 1;
        if (i <= j) then
            begin
            swap(x[i],x[j]);
            swap(y[i],y[j]);
            i := i + 1;
            j := j - 1;
            end;
        end;
    if (i < r) then 
        qsort(x,y,i,r);
    if (j > l) then
        qsort(x,y,l,j);
    end;
///////////////////////////////////////
begin
//assign(input,'ucode_dieukhienrobot.inp');reset(input);
readln(n);
for i := 1 to n do
    readln(x[i],y[i]);
readln(m);
qsort(x,y,1,n);

end.