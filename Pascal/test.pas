var a,tmp:ansistring;
    i,md:longint;
///////////////////////////////////////
begin
readln(a);
md := 0;
while (length(a) > 1) do
    begin
    tmp := '';
    for i := 1 to length(a) do
        begin
        if (i mod 2 <> md) then
            tmp := tmp + a[i];
        end;
    md := (md + 1) mod 2;
    a := tmp;
    end;
writeln(a);
end.