var a,b:ansistring;
    i,d,s:longint;
///////////////////////////////////////
begin
readln(a);
a := a + '.';
for i := 1 to length(a) do
    begin
    if (a[i] in ['0'..'9']) then
        b := b + a[i]
    else
        begin
        if (b <> '') then
            begin
            d := d + 1;
            b := '';
            end;
        end;
    end;
writeln(d);
end.