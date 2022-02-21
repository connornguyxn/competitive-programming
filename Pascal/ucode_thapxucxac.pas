var n,num14,i:longint;
    a:int64;
///////////////////////////////////////
begin
readln(n);
for i := 1 to n do
    begin
    read(a);
    num14 := a mod 14;
    if ((a > 14) and (num14 >= 1) and (num14 <= 6)) then
        writeln('YES')
    else
        writeln('NO');
    end;
end.