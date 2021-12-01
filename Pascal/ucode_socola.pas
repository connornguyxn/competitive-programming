var n,m,k,i:longint;
begin
readln(n);
readln(m);
readln(k);
for i:=1 to n do
    if (i*m=k) then
        begin
        writeln('YES');
        halt;
        end;
for i:=1 to m do
    if (i*n=k) then
        begin
        writeln('YES');
        halt;
        end;
        writeln('NO');
end.
