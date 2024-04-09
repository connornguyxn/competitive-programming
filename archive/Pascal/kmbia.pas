uses crt;
var n,t:longint;

begin
clrscr;
readln(t);
while (t div 10<>0) do
    begin
    t:=(t mod 10)+((t div 10)*3);
    end;
writeln(t);
readln
end.
