var x,d:int64;
k,i:longint;

begin
readln(x,k,d);
for i:=1 to k do
    if abs(x+d)<abs(x-d) then
        x:=x+d
    else
        x:=x-d;
writeln(abs(x));
end.