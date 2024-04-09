type ar=array[0..100000000] of longint;
var d,kq:ar;
    i,n,a,b,mx,j:longint;
//////////////////////////////////////
procedure qsort(var a:ar; l,r:longint);
var i,j,x,tg:longint;
    begin
    i:=l;
    j:=r;
    x:=a[(i+j) div 2];
    while i<=j do
        begin
        while a[i]<x do 
            begin
            i:=i+1;
            end;
        while a[j]>x do
            begin
            j:=j-1;
            end;
        if i<=j then
            begin
            tg:=a[i];
            a[i]:=a[j];
            a[j]:=tg;
            i:=i+1;
            j:=j-1;
            end;
        end;
    if i<r then 
        qsort(a,i,r);
    if j>l then
        qsort(a,l,j);
    end;
//////////////////////////////////////
begin
assign(input,'order.inp');reset(input);
//assign(output,'order.out');rewrite(output);
readln(n);
readln(kq[1],mx);
d[kq[1]]:=d[kq[1]]+mx;
j:=2;
for i:=2 to n do
    begin
    readln(a,b);
    d[a]:=d[a]+b;
    if (d[a] > mx) then
        begin
        mx:=d[a];
        j:=1;
        kq[j]:=a;
        end
    else if (d[a] = mx) then
        begin
        j:=j+1;
        kq[j]:=a;
        end;
    end;
writeln(mx);
qsort(kq,1,j);
for i:=1 to j do
    write(kq[i],' ');
end.