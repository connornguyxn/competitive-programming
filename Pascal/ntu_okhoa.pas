var i,n,t:qword;
///////////////////////////////////////
begin
readln(n);
t := 0;
i := 1;
while (i <= n - 1) do
    begin
    t := t + (n - i) * i;
    i := i + 1;
    end;
t := t + n;
writeln(t);
end.