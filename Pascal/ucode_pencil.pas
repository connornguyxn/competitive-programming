var a,b:array[-1..100000000] of longint;
    m,n,d,i,p:longint;
///////////////////////////////////////
begin
assign(input,'ucode_pencil.inp');reset(input);
readln(n,m);
for i := 1 to n do
    read(a[i]);
for i := 1 to m do
    begin
    read(p);
    a[p] := 1;
    end;
d := 0;
for i := 1 to 10 do
    write(a[i],' ');
writeln();
for p := 1 to n do
    begin
    if (a[p + 1] = 1) then
        begin
        a[p + 1] := 0;
        continue;
        end;
    if (a[p - 1] = 1) then
        begin
        a[p - 1] := 0;
        continue;
        end;
    d := d + 1;
    end;
writeln(d);
end.