var a:array[0..100000000] of boolean;
    i,n,d,c:longint;
///////////////////////////////////////
begin
readln(n);
for i := 1 to n do
    begin
    read(c);
    if (not d[c]) then
        begin
        d := d + 1;
        d[c] := true;
        end;
    end;
writeln(d);
end.