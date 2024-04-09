type ar=array[1..1000000] of longint;
var a:ar;
    i,j,m,d,n,k:longint;
/////////////////////////////////////////////
procedure qsort(var a:ar; l,r:longint);
var i,j:longint;
x,tg:int64;
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
///////////////////////////////////////////////
begin
readln(n,m,k);
d:=0;
for i:=1 to n do
    for j:=1 to m do
        begin
        d:=d+1;
        a[d]:=i*j;
        end;
qsort(a,1,d);
writeln(a[k]);
end.