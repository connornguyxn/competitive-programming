var n,i,d,c:longint;
///////////////////////////////////////
begin
readln(n);
d := 0;
for i := 1 to n do
    begin
    c := i;
    while (c mod 5 = 0) do
        begin
        d := d + 1;
        c := c div 5;
        end;
    end;
writeln(d);
end.