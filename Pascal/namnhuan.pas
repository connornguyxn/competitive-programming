var m,y:longint;
begin
readln(m,y);
if (m in [1,3,5,7,8,10,12]) then
    writeln('31')
else
    if (m in [4,6,9,11]) then
        writeln('30')
    else
        if (y mod 400=0) or ((y mod 4=0) and (y mod 100<>0)) then 
            writeln('29')
        else
            writeln('28');
end.
