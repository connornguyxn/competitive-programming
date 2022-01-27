var n,k,i:longint;
    t:qword;
///////////////////////////////////////
begin
readln(n,k);
t := 0;
for i := 1 to (k - 1) do
    begin
    if (i <= n mod k) then
        begin
        t := t + (n div k + 1) * (n - (n div k + 1) * i);
        end
    else
        begin
        t := t + (n div k) * (n div k) * (k - i);
        end;
    end;
writeln(t);
end.