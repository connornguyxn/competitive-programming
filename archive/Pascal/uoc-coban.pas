uses crt;
var a,b,d,t,i:longint;

begin
clrscr;
readln(a);
for i:=1 to trunc(sqrt(a)) do
    if a mod i=0 then
        begin
        d:=d+1;
        b:=i;
        while sqr(b)<=a do
            begin
            t:=t+b;
            d:=d+1;
            b:=sqr(b);
            end;
        t:=t+i;
        end;
writeln(d);
writeln(t);
if d=2 then
    writeln('YES')
else
    writeln('NO');
readln
end.
