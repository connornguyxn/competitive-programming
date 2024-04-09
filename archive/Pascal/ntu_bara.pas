var n,k:longint;
///////////////////////////////////////
begin
readln(n,k);
n := n * 2;
if (n mod k = 0) then
    begin
    writeln((n div k) * 10)
    end
else
    begin
    writeln((n div k) * 10 + 5)
    end;
end.