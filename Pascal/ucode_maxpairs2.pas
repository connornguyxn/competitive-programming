type ar=array[1..1000000] of longint;
var a:ar;
n,i:longint;
/////////////////////////////////////////////
procedure quicksort(var a:ar;l,r:longint);
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
///////////////////////////////////////////////////////
begin
assign(input,'ucode_maxpairs2.inp');reset(input);
assign(output,'ucode_maxpairs2.out');rewrite(output);
readln(n);
for i:=1 to n do
    read(a[i]);
quicksort(a,1,n);
if a[n]<0 then
    writeln(a[1]*a[2])
else
    if a[n-1]>=0 then
        writeln(a[n]*a[n-1])
    else
        if a
end.
