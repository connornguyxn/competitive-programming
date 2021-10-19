type ar=array[1..1000000] of longint;
var mg:ar;
n,i:longint;
////////////////////////////////////
procedure quicksort(var a:ar; l,r:longint);
var i,j:longint;
x,tg:int64;
begin
i:=l;
j:=r;
x:=a[(i+j) div 2];
while i<=j do
    begin
    while a[i]<x do inc(i);
    while a[j]>x do dec(j);
    if i<=j then
        begin
        tg:=a[i];
        a[i]:=a[j];
        a[j]:=tg;
        inc(i);
        dec(j);
        end;
    end;
if i<r then quicksort(a,i,r);
if j>l then quicksort(a,l,j);
end;
////////////////////////////
begin
readln(n);
for i:=1 to n do read(mg[i]);
quicksort(mg,1,n);
for i:=1 to n do write(mg[i],' ');
end.
