var x1,y1,x2,y2,d:longint;
///////////////////////////////////////
begin
readln(d,x1,y1,x2,y2);
d := d * 2;
if (x1 - x2 = y1 - y2) and (frac((x1 - x2) * sqrt(2)) = 0) then
    begin
    writeln(trunc((x1 - x2) * sqrt(2)) div d);
    end
else
    begin
    writeln(abs(x1 - x2) div d + abs(y1 - y2) div d);
    end;
end.
. . . . . . . . .
. . . . . . . . .
. . . . . . . . .
. . . . . . . . .
. . . . . . . . .
. . . . . . . . .
. . . . . . . . .