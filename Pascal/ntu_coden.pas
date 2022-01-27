var m,n,d:int64;
///////////////////////////////////////
begin
readln(m,n);
if (m mod 2 = 0) and (n mod 2 = 0) then
    begin
    writeln((m * n) div 4);
    end
else
    begin
    d := ((m - (m mod 2)) * (n - (n mod 2))) div 4;
    d := d + (m * (n mod 2) + n * (m mod 2)) div 2;
    d := d + (m * (n mod 2) + n * (m mod 2)) mod 2;
    writeln(d);
    end;
end.