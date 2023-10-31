var n,i:longint;
begin
readln(n);
i:=2;
while n>1 do
    begin
    if n mod i = 0 then
        begin
        write(i,'*');
        n:= n div i;
        end;
    else i:=i+1;
    end;
writeln(n)
end;