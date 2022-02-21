var a,b,i:longint;
///////////////////////////////////////
function untln(n:longint):longint;
    var i,sq:longint;
    /////////////////
    begin
    untln := n;
    if (n mod 2 = 0) then
        begin
        untln := 2;
        while (n mod 2 = 0) do
            n := n div 2;
        end;
    i := 3;
    sq := trunc(sqrt(n));
    while ((n > 1) and (i <= sq)) do
        begin
        if (n mod i = 0) then
            begin
            untln := i;
            while (n mod i = 0) do
                n := n div i;
            end;
        i := i + 2;
        end;
    end;
///////////////////////////////////////
begin
readln(a,b);
a := untln(a);
b := untln(b);
writeln(a,' ',b);
if (a = b) then
    writeln('La cap so than thiet')
else
    writeln('Khong la cap so than thiet');
end.