type ar=array[1..1000000] of longint;
var a,b:ar;
x,y,i,d,n:longint;
/////////////////////////////////////////////
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

//////////////////////////////////////////
begin
assign(input,'ucode_countboth.inp');reset(input);
assign(output,'ucode_countboth.out');rewrite(output);
readln(n,x,y);
for i:=1 to x do
    read(a[i]);
for i:=1 to y do
    read(b[i]);
quicksort(a,1,x);
quicksort(b,1,y);
for i:=1 to
end.
