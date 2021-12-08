var n,i:longint;
    t:qword;

begin
readln(n);
t:=1;
for i:=2 to trunc(sqrt(n)) do
    begin
    if n mod i=0 then
        t:=t+i+n div i;
    if t>n then
        begin
        writeln('NO');
        halt;
        end;
    end;
if t=n then
    writeln('YES')
else
    writeln('NO');
end.