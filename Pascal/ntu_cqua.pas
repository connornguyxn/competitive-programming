var d:array[1..2] of longint;
    i,n,c:longint;
///////////////////////////////////////
function hi(a,b:longint):longint;
    /////////////////
    begin
    if (a > b) then
        exit(a);
    exit(b);
    end;
///////////////////////////////////////
begin
readln(n);
for i := 1 to n do
    begin
    read(c);
    d[c div 100] := d[c div 100] + 1;
    end;
if (hi(-1,d[1] - (d[2] mod 2) * 2) mod 2 = 0) then
    writeln('YES')
else
    writeln('NO');

end.