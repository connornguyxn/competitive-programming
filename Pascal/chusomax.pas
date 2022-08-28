var a,b:ansistring;
    i:longint;
///////////////////////////////////////
begin
readln(a);
for i := 9 downto 0 do
    begin
    str(i,b);
    if (pos(b,a) > 0) then
        begin
        writeln(b);
        exit();
        end;
    end;
end.

//0 1 2 3 4 5 6 7 8 9