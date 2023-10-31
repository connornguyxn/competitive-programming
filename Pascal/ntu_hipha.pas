var n,t,a:int64;
i:longint;

begin
readln(n);
t:=0;
for i:=1 to n do
    begin
    read(a);
    if a=1 then inc(t)
        else dec(t);
    end;
writeln(abs(t));
end.