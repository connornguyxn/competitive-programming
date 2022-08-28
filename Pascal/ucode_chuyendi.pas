var n,i,t:longint;
///////////////////////////////////////
begin
readln(n,i);
t := 0;
i := i + 1;
while true do
    begin
    t := t + i;
    if (n - i < i) then
        begin
        writeln(t + n - i);
        halt;
        end;
    i := i + i;
    end;
end.