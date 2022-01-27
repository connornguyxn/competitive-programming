var a:array[1..1000000] of longint;
    i,n,w,j,tmp:longint;
///////////////////////////////////////
begin
readln(n,w);
for i:=1 to n do
    read(a[i]);
for i:=1 to (n - 1) do
    for j:=(i + 1) to n do
        begin
        if (a[i] > a[j]) then
            begin
            tmp := a[i];
            a[i] := a[j];
            a[j] := tmp;
            end;
        end;
i := 0;
while (w >= 0) do
    begin
    i := i + 1;
    w := w - a[i];
    end;
writeln(i - 1);
end.