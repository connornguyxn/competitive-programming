var i,n:longint;
    mx,mn,t:int64;
    l,r:array[0..100000000] of int64;
///////////////////////////////////////
procedure swap(var a,b:int64);
    var tmp:int64;
    /////////////////
    begin
    tmp := a;
    a := b;
    b := tmp;
    end;
///////////////////////////////////////
procedure qsort(t,p:longint);
    var i,j,x,tg:longint;
    /////////////////
    begin
    i := t;
    j := p;
    x := l[(i + j) div 2];
    while (i <= j) do
        begin
        while (l[i] < x) do 
            i := i + 1;
        while (l[j] > x) do
            j := j - 1;
        if (i <= j) then
            begin
            swap(l[i],l[j]);
            swap(r[i],r[j]);
            i := i + 1;
            j := j - 1;
            end;
        end;
    if (i < p) then 
        qsort(i,p);
    if (j > t) then
        qsort(t,j);
    end;
///////////////////////////////////////
begin
//assign(input,'ntu_doannp2.inp');reset(input);
readln(n);
for i := 1 to n do
    readln(l[i],r[i]);
qsort(1,n);
mn := l[1];
mx := r[1];
for i := 1 to (n - 1) do
    begin
    if (mx > l[i + 1]) then
        begin
        if (r[i + 1] > mx) then
            mx := r[i + 1];
        end
    else
        begin
        t := t + mx - mn;
        mn := l[i + 1];
        mx := r[i + 1];
        end;
    end;
t := t + mx - mn;
writeln(t);
end.
