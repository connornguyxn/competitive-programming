var a,n,d,mx,i:longint;

begin
readln(n);
d := 0;
mx := 0;
for i:=1 to n do
    begin
    read(a);
    if (a = 0) then
        d := d + 1
    else
        begin
        if (d > mx) then
            mx := d;
        d := 0
        end
    end;
if (d > mx) then
    mx := d;
if (mx = 0) then
    writeln(-1)
else
    writeln(mx);
end.