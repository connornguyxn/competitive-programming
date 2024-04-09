var a:array[0..100000000] of longint;
    i,n,d:longint;
///////////////////////////////////////
begin
readln(n);
read(a[1]);
d := a[1];
for i := 2 to n do
    begin
    read(a[i]);
    d := d + abs(a[i] - a[i - 1]);
    end;
writeln(d);
end.