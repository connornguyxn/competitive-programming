type ar=array[1..1000000] of longint;
var a,b:ar;
n,i,test,tests,kq:longint;
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
assign(input,'ucode_identical.inp');reset(input);
assign(output,'ucode_identical.out');rewrite(output);
readln(tests);
for test:=1 to tests do
begin
readln(n);
for i:=1 to n do
    read(a[i]);
for i:=1 to n do
    read(b[i]);
quicksort(a,1,n);
quicksort(b,1,n);
kq:=1;
for i:=1 to n do
    if a[i]<>b[i] then
        kq:=0;
writeln(kq);
end;
end.
