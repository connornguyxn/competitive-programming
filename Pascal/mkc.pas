var a:ansistring;
i,b,kt,t:longint;

begin
for i:=1 to length(a) do
    begin
    val(a[i],b,kt);
    t:=t+b;
    end;
writeln(b);
end.