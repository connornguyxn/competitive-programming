var a,b,c:longint;
///////////////////////////////////////
begin
readln(a,b,c);
while ((a <> 0) or (b <> 0) or (c <> 0)) do
    begin
    if ((a = b) or (b = c) or (c = a)) and ((a = 0) or (b = 0) or (c = 0)) then 
        begin
        continue;
        end;
    if (b div a = c div b) and (b mod a = 0) and (c mod b = 0) then
        begin
        writeln('GP ',c * (c div b));
        end
    else if (b - a = c - b) then
        begin
        writeln('AP ',c + c - b);
        end;
    readln(a,b,c);
    end;
end.