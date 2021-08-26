var b,t,kt,i:longint;
a:ansistring;

begin
readln(a);
for i:=1 to length(a) do
    begin
    val(a[i],b,kt);
    t:=t+b;
    end;
if b mod 10=9 then writeln('YES')
    else writeln('NO');
end.