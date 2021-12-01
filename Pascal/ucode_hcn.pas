var a,b,c,d,i,j:longint;

begin
readln(a);
readln(b);
readln(c);
readln(d);
if ((a=b) and (c=d)) or ((a=c) and (b=d)) or ((a=d) and (b=c)) then
    writeln('YES')
else
    writeln('NO');
end.
