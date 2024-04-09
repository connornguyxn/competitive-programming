var n,i,d:longint;
///////////////////////////////////////
begin
readln(n);
d := d + n div 2;
n := n mod 2;
if (n = 1) then
    n := 0;
i := 3;
while (n <> 0) do
    begin
    d := d + n div i;
    n := n mod i;
    i := i + 2;
    end;
writeln(d);
end.