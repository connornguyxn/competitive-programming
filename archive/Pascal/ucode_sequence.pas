var n,k,a,ap,d,i:longint;
///////////////////////////////////////
begin
readln(n,k);
ap := 1;
for i := 1 to n do
    begin
    read(a);
    if (a = ap) then
        d := d + 1
    else
        d := 1;
    ap := a;
    end;
if (d + k > n) then
    writeln(n - d)
else
    writeln(-1);
end.