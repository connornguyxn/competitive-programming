var a:ansistring;
    d,i:longint;
///////////////////////////////////////
begin
readln(a);
a := ' ' + a;
for i:=1 to length(a) do
    begin
    if (a[i] <> ' ') and (a[i - 1] = ' ') then
        d := d + 1;
    end;
writeln(d);
end.