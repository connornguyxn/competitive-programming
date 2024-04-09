var n,i,l,r,key,tmp,mid:longint;
////////////////////////////////////
begin
readln(n);
n := n * 2;
for i := 1 to trunc(sqrt(n)) do
    begin
    tmp := i * (i + 1);
    key := n - tmp;
    l := i;
    r := trunc(sqrt(n));
    while (l <= r) do
        begin
        mid := (l + r) div 2;
        if (mid * (mid + 1) < key) then
            l := mid + 1
        else if (mid * (mid + 1) > key) then
            r := mid - 1
        else
            begin
            writeln('YES');
            halt;
            end;
        end;
    end;
writeln('NO');
end.
