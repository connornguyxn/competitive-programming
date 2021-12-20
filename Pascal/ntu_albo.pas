var n,k:int64;
//////////////////////////////////////
begin
readln(n,k);
if n mod k mod 2 = 0 then
    writeln('Alice will win')
else
    writeln('Bob will win');
end.