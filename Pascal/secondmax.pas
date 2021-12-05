type ar=array[1..1000000] of longint;
var a:ar;
    i,n,mx,p:longint;
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
            i:=i+1;
        while a[j]>x do
        j:=j-1;
        if i<=j then
            begin
            tg:=a[i];
            a[i]:=a[j];
            a[j]:=tg;
            i:=i+1;
            j:=j-1;
            end;
        end;
    if i<r then qsort(a,i,r);
    if j>l then qsort(a,l,j);
    end;
////////////////////////////////////
begin
readln(n);
read(a[1]);
mx:=a[1];
p:=1;
for i:=2 to n do
    begin
    read(a[i]);
    if a[i]>mx then
        begin
        mx:=a[i];
        p:=i;
        end;
    end;
qsort(a,1,n);
i:=2;
while a[i]=a[1] do
    i:=i+1;
writeln(a[1]);
writeln(a[i]);
writeln(p);
end.