var x,i,j,kt:longint;
///////////////////////////////////////
begin
readln(x);
for i:=1 to (x div 2) do
    begin
    j:=i;
    while (sqr(j) + sqr(i) < sqr(x - i - j)) do
        j:=j+1;
    if (sqr(j) + sqr(i) = sqr(x - i - j)) then
        begin
        kt := 1;
        break;
        end;
    end;
writeln(kt);
end.