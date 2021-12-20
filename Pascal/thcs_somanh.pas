var a,kq:array[1..100000000] of longint;
    i,n,d:longint;
////////////////////////////////////////
begin
readln(n);
for i:=1 to n do
    read(a[i]);
d:=1;
kq[1]:=a[n];
for i:=n-1 downto 1 do
    if a[i]>kq[d] then
        begin
        d:=d+1;
        kq[d]:=a[i];
        end;
writeln(d);
for i:=d downto 1 do
    write(kq[i],' ');
end.