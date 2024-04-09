var a:array[1..11] of longint;
    i,n,c,d:longint;
    res:ansistring;
///////////////////////////////////////
function stri(a:longint):ansistring;
    begin
    str(a,stri);
    end;
///////////////////////////////////////
begin
readln(n);
for i := 1 to n do
    begin
    read(c);
    a[c] := a[c] + 1;
    if (a[c] = 3) then
        begin
        d := d + 1;
        res := res + stri(c) + ' ';
        end;
    end;
writeln(d);
writeln(res);
end.
    