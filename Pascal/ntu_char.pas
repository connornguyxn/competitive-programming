var a,b:ansistring;
i:longint;

begin
readln(a);
for i:=1 to length(a) do
    if pos(a[i],b)=0 then b:=b+a[i];
writeln(length(b));
end.