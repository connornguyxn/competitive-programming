type ar=array[1..1000000] of longint;
var d7,d5:ar;
    dn:string;
    d7n,d5n,i,n,c:longint;
///////////////////////////////////
function stri(n:longint):ansistring;
    begin
    str(n,stri);
    end;
//////////////////////////////////////
procedure qsort(var a:ar; l,r:longint);
    var i,j,x,tg:longint;
    begin
    i:=l;
    j:=r;
    x:=a[(i+j) div 2];
    while i<=j do
        begin
        while a[i]<x do
            i:=i+1;
        while a[j]>x do
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
readln(n);
d7n:=1;
d5n:=1;
for i:=1 to n do
    begin
    read(c);
    if c mod 7=0 then
        begin
        d7[d7n]:=c;
        d7n:=d7n+1;
        end
    else
        if c mod 5=0 then
            begin
            d5[d5n]:=c;
            d5n:=d5n+1;
            end
        else
            dn:=dn+stri(c)+' ';
    end;
d5n:=d5n-1;
d7n:=d7n-1;
qsort(d7,1,d7n);
qsort(d5,1,d5n);
for i:=1 to d7n do
    write(d7[i],' ');
write(dn);
for i:=1 to d5n do
    write(d5[i],' ');
end.