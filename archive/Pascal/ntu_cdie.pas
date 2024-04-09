var a:array[0..100000000] of longint;
i,n,m,t:longint;
//////////////////////////////////
procedure qsort(var a:array of longint;l,r:longint);
var i,j,tmp,x:longint;
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
            tmp:=a[i];
            a[i]:=a[j];
            a[j]:=tmp;
            i:=i+1;
            j:=j-1;
            end;
        end;
    if i<r then qsort(a,i,r);
    if j>l then qsort(a,l,j);
    end;
/////////////////////////////////
begin
assign(input,'ntu_cdie.inp');reset(input);
readln(n,m);
for i:=1 to n do
    read(a[i]);
if m=1 then
    begin
    writeln(0);
    halt;
    end;
qsort(a,1,n);
i:=1;
for i:=1 to n do
    begin
    t:=t+a[i];
    if t<m then
        begin
        t:=t-1;
        continue;
        end;
    if t=m then
        writeln(i)
    else
        writeln(i);
    halt;
    end;
writeln(-1);
end.