var s,v1,v2,t1,t2:int64;
///////////////////////////////////////
begin
readln(s,v1,v2,t1,t2);
t1 := v1 * s + t1 * 2;
t2 := v2 * s + t2 * 2;
if (t1 < t2) then
    writeln('First')
else if (t1 > t2) then
    writeln('Second')
else
    writeln('Friendship');
end.