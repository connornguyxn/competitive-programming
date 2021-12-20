var n:int64;
//////////////////////////////////////
begin
readln(n);
if trunc(sqrt(n*2))*(trunc(sqrt(n*2))+1) div 2 = n then
    writeln('YES')
else
    writeln('NO');
end.