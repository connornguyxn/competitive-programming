var i,n,t:qword;
///////////////////////////////////////
begin
readln(n);
t := 0;
i := 1;
while (i <= n - 1) do
    begin
    t := t + (n mod 1000000007 - i mod 1000000007) mod 1000000007 * i mod 1000000007;
    i := i + 1;
    end;
t := t mod 1000000007 + n mod 1000000007;
writeln(t);
end.