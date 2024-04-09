var a,h,i,n,d:longint;
////////////////////////////////////
begin
readln(n,h);
for i:=1 to n do
    begin
    read(a);
    if (a > h) then
        begin
        d := d + 1;
        end;
    end;
writeln(d+n);
end.