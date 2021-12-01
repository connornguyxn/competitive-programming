var a:array[1..9] of longint;
    np:array[1..100000000] of longint;
    n,d,i,inp:longint;
///////////////////////////////////////
function stri(number:int64):ansistring;
begin
str(number,stri);
end;
////////
function int(strin:ansistring):int64;
var check:longint;
begin
val(strin,int,check);
end;
////////
function join(a:array of longint):ansistring;
var i:longint;
begin
join:='';
for i:=1 to n do
    join:=join+stri(a[i]);
end;
////////
procedure sinhnp(k:longint);
var i:longint;
begin
if k>n then 
    begin
    np[d]:=int(join(a));
    d:=d+1;
    end
else
    for i:=0 to 1 do
        begin
        a[k]:=i;
        sinhnp(k+1);
        end;
end;
/////////////////////
procedure quicksort(var a:array of longint; l,r:longint);
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
readln(n);
d:=1;
sinhnp(1);
quicksort(np,1,d);
for i:=1 to d do
    writeln(np[i]);
end.