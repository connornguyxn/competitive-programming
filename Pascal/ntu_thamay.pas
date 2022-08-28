type ar=array[0..1000000] of longint;
var a:ar;
    i,n,k,ck:longint;
    t:qword;
//////////////////////////////////////
procedure qsort(var a:ar; l,r:longint);
    var i,j,x,tg:longint;
    begin
    i:=l;
    j:=r;
    x:=a[(i+j) div 2];
    while i<=j do
        begin
        while a[i]>x do
            i:=i+1;
        while a[j]<x do
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
//assign(input,'ntu_thamay.inp');reset(input);
readln(n,k);
for i:=1 to n do
    read(a[i]);
qsort(a,1,n);
a[0]:=1;
ck:=k;
for i:=1 to n do
    begin
    if ck=0 then
        begin
        t:=t+abs(a[i-1]-1)+abs(a[i]-1);
        ck:=k-1;
        end
    else
        begin
        t:=t+abs(a[i-1]-a[i]);
        ck:=ck-1;
        end;
    end;
t:=t+a[n]-1;
writeln(t);
end.