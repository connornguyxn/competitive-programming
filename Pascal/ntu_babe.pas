var a,b,i,t:longint;
//////////////////////////////////////
function uoc(a:longint):longint;
    begin
    uoc := 0;
    for i := 1 to (a - 1) do
        begin
        if (a mod i = 0) then
            uoc := uoc+i;
        end;
    end;
//////////////////////////////////////
begin
readln(a,b);
if (uoc(a) = b) and (uoc(b) = a) then
    writeln('YES')
else
    writeln('NO');
end.