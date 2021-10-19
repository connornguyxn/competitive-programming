var a,n,mn,i:longint;

begin
readln(n);
read(mn);
for i:=2 to n do
    begin
    read(a);
    if a<mn then
        mn:=a;
    end;
writeln(mn*(n-1));
end.