var a,b,tmp:ansistring;
    i:longint;
///////////////////////////////////////
begin
readln(a);
readln(b);
if (length(a) > length(b)) then
    begin
    tmp := a;
    a := b;
    b := tmp;
    end;
i := length(a);
while ((i > 0) and (a[i] = b[i + length(b) - length(a)])) do
    begin
    i := i - 1;
    end;
writeln((length(a) - i) + (length(b) - i))
end.