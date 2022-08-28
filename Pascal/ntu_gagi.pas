var n,k,d:qword;
///////////////////////////////////////
begin
readln(k,n);
d := 0;
while (k * 2 <= n) do
    begin
    k := k * 2;
    d := d + 1;
    end;
writeln(d);
end.