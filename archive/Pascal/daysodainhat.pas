var a,mx,b:ansistring;
    i:longint;
///////////////////////////////////////
begin
readln(a);
for i := 1 to length(a) do
    begin
    if (a[i] in ['0'..'9']) then
        b := b + a[i]
    else
        begin
        writeln('else at a[i] = ',a[i]);
        if (length(b) > length(mx)) then
            mx := b;
        b := ''
        end;
    end;
writeln(length(mx));
writeln(mx);
end.