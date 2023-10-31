uses crt;
var a:array[1..100000000] of int64;
i,n,d:longint;
a,k:int64;

begin
clrscr;
readln(n,k);
for i:=1 to n do
    read(a[i]);
for i:=1 to n-1 do
    begin
    d:=1;
    for j:=1 to n do
        if a[i]=a[j] then d:=d+1;
    if d>1 then write(a[i],' ',d);
    end;
writeln
end.