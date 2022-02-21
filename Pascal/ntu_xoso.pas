var d:array[0..1] of longint;
    i,n,a:longint;
    t:int64;
///////////////////////////////////////
begin
readln(n);
for i := 1 to n do
    begin
    read(a);
    d[a mod 2] := d[a mod 2] + 1;
    end;
if (d[1] mod 2 = 1) then
    t := d[0] * d[1]
else
    t := (d[0] * (d[0] - 1)) div 2 + (d[1] * (d[1] - 1)) div 2;
writeln(t);
end.