var b,t,kt,i:longint;
    a:ansistring;

begin
readln(a);
for i:=1 to length(a) do
    begin
    val(a[i],b,kt);
    t := t + b;
    end;
if (t mod 10 = 9) then
    begin
    writeln('YES')
    end
else
    begin
    writeln('NO');
    end;
end.