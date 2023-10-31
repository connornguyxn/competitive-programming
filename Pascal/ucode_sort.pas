type ar=array[1..1000000] of int64;
var a:ar;
b:ansistring;
n,kt,i:longint;
///////////////////////////////////////////////////////
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
///////////////////////////////////////////////
begin
readln(b);
i:=1;
while pos(' ',b)<>0 do
    begin
    val(copy(b,1,pos(' ',b)-1),a[i],kt);
    delete(b,1,pos(' ',b));
    i:=i+1;
    end;
val(b,a[i],kt);
n:=i;
quicksort(a,1,n);
for i:=n downto 1 do
    write(a[i],' ');
end.
