var a:array[0..100000000] of longint;
    i,mx:longint;

begin
readln(n);
for i := 1 to n do
    read(a[i]);
for i := 2 to n do
    if (a[i] * a[i - 1] > 0) then
        begin
        writeln('Doan khong dan dau');
        halt;
        end;
writeln('Doan dan dau');
end.