var t,a,i,n:integer;

begin
read(n);
t:=0;
for i:=1 to n do
    begin
    read(a);
    t:=t+a;
    end;
writeln(t);
end.