var n:longint;
ssh:longint;

begin
readln(n);
if n mod 2=0 then
    n:=n-1;
ssh:=((n-1) div 2)+1;
writeln(((n+1) * ssh) div 2);
end.
