var a:array[0..100000000] of longint;
    mx,cmx,d,i,n:longint;
///////////////////////////////////////
begin
readln(n);
mx := 0;
for i := 1 to n do
    begin
    read(a[i]);
    if (a[i] > mx) then
        mx := a[i];
    end;
cmx := 0;
d := 0;
while (a[n] <> mx) do
    begin
    if (a[n] > cmx) then
        begin
        cmx := a[n];
        d := d + 1;
        end;
    n := n - 1;
    end;
writeln(d);
end.