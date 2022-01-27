var a,c:ansistring;
    i,l,r,mx:longint;
///////////////////////////////////////
begin
readln(a);
l := 1;
r := 1;
mx := 0;
c := '';
while (r <= length(a)) do
    begin
    if (pos(a[r],c) = 0) then
        begin
        c := c + a[r];
        end
    else
        begin
        l := l + pos(a[r],c);
        c := copy(a,l,r - l + 1);
        end;
    if (mx < length(c)) then
        mx := length(c);
    r := r + 1;
    end;
writeln(mx);
end.