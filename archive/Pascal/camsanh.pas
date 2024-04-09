type ar=array[1..1000000] of longint;
var a:ar;
    i,n,k,mx:longint;

procedure sort(var a:ar;l,r:longint);
var i,j,x,tmp:longint;
begin
i:=l;
j:=r;
x:=a[(l+r) div 2];
while i<=j do
    begin
    while a[i]<x do
        i:=i+1;
    while a[j]>x do
        j:=j-1;
    if i<=j then
        begin
        tmp:=a[i];
        a[i]:=a[j];
        a[j]:=tmp;
        i:=i+1;
        j:=j-1;
        end;
    end;
if i<r then
    sort(a,i,r);
if j>l then
    sort(a,l,j);
end;
///////////////////////////////
begin
readln(n);
for i:=1 to n do
    read(a[i]);
sort(a,1,n);
mx:=0;
for i:=1 to n do
    begin
    if a[i]=a[i-i] then
        continue;
    if a[i]*(n-(i-1))>mx then
        mx:=a[i]*(n-(i-1))
    end;
writeln(mx);
end.