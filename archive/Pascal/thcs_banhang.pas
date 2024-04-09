type ar=array[1..1000000] of longint;
var a:ar;
    i,mx,n,k:longint;
//////////////////////////////////////////////
procedure sort(var a:ar;l,r:longint);
var i,j,tmp,m:longint;
begin
i:=l;
j:=r;
m:=a[(l+r) div 2];
while i<=j do
    begin
    while a[i]<m do
        i:=i+1;
    while a[j]>m do
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
/////////////////////////////////////////////
begin
readln(n);
for i:=1 to n do
    read(a[i]);
sort(a,1,n);
k:=1;
mx:=0;
for i:=1 to n do
    if a[i]*(n-(i-1))>mx then
        begin
        mx:=a[i]*(n-(i-1));
        k:=a[i];
        end;r
writeln(k);
end.
//4 6 3 6 1 5 10