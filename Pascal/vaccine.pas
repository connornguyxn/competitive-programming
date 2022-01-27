var a,b,m,n:longint;
///////////////////////////////////////
begin
readln(m,n,a,b);
if (m >= n) then
    begin
    writeln(0);
    end
else
    begin
    if ((n - m) mod (a + b) = 0) then
        writeln((n - m) div (a + b))
    else
        writeln((n - m) div (a + b) + 1);
    end;
end.