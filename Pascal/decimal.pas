var a:ansistring;
    m,i,p:longint;
///////////////////////////////////////
begin
readln(a);
readln(m);
p := pos('.',a);
if (p = 1) then
    write(0);
if (p = 0) then
    begin
    write(a,'.');
    p := length(a);
    end
else
    write(copy(a,1,p));
p := p + 1;
for i := 1 to m do
    begin
    if ((p > length(a)) or (p = 0)) then
        write(0)
    else
        write(a[p]);
    p := p + 1;
    end;
end.