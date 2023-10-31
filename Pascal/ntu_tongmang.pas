var s,a:int64;
///////////////////////////////////////
begin
s := 1;
while (not eoln) do
    begin
    read(a);
    s := s + a - 1;
    end;
writeln(s);
end.