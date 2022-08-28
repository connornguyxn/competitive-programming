uses crt;
var a:ansistring;
t:int64;
b,i,kt:longint;

begin
clrscr;
readln(a);
while length(a)<>1 do
    begin
    t:=0;
    for i:=1 to length(a) do
        begin
        val(a[i],b,kt);
        t:=t+b;
        end;
    str(t,a);
    end;
writeln(a);
readln
end.
