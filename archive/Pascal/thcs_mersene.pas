var a:array[1..8] of string = ('2147483647','524287','131071','8191','127','31','7','3');
    i:longint;
    c:ansistring;
///////////////////////////////////////
begin
readln(c);
readln(c);
c := c + ' ';
for i:=1 to 8 do
    begin
    if (pos(a[i] + ' ',c) <> 0) then
        begin
        writeln(a[i]);
        exit();
        end;
    end;
writeln(-1);
end.