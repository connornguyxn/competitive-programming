var a:array[0..100000000] of longint;
    i,j,n,mx:longint;

begin
readln(n);
for i := 1 to n do
    begin
    read(a[i]);
    a[i] := a[i] + a[i - 1];
    end;
mx := a[2] - a[1];
for i := 1 to (n - 1) do
    for j := (i + 1) to n do
        if (a[j] - a[i - 1] > mx) then
            mx := a[j] - a[i - 1];
writeln(mx);
end.