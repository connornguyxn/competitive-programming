var a,c,kq:ansistring;
    d,i:longint;
/////////////////////////////////////
function stri(a:longint):ansistring;
    begin
    str(a,stri);
    end;
//////////////////////////////////////
begin
readln(a);
c:=a[1];
d:=1;
for i:=2 to length(a) do
    begin
    if (a[i] = c) then
        begin
        d:=d+1;
        end
    else
        begin
        if (d = 1) then
            kq:=kq+c
        else
            kq:=kq+stri(d)+c;
        c:=a[i];
        d:=1;
        end;
    end;
if (d = 1) then
    kq:=kq+c
else
    kq:=kq+stri(d)+c;
writeln(kq);
end.