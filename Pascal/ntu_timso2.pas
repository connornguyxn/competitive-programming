var n,i:longint;
    res:string = '';
///////////////////////////////////////
function stri(a:longint):ansistring;
    begin
    str(a,stri);
    end;
///////////////////////////////////////
begin
readln(n);
if (n < 10) then
    begin
    if (n = 0) then
        writeln(10)
    else
        writeln(n);
    halt;
    end;
for i := 9 downto 2 do
    begin
    while (n mod i = 0) do
        begin
        res := stri(i) + res;
        n := n div i;
        end;
    end;
if (n > 1) then
    begin
    writeln(-1);
    end
else
    begin
    writeln(res);
    end;
end.