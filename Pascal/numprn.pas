var i:longint;
    n,m:int64;
    a:array[0..100000000] of boolean;
///////////////////////////////////////
begin
readln(n);
for i := 1 to 1000000 do
    begin
    if (n mod (i * (i + 1)) = 0) then
        begin
        write(i,' ');
        a[i] := true;        
        end;
    end;
for i := 1000000 downto 1 do
    begin
    m := n div i * 4 + 1;
    if (m < 4) then
        continue;
    if ((frac(sqrt(m)) = 0) and ((trunc(sqrt(m)) - 1) mod 2 = 0)) then
        begin
        if (not a[(trunc(sqrt(m)) - 1) div 2]) then
            write((trunc(sqrt(m)) - 1) div 2,' ');
        end;
    end;
end.