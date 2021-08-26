uses crt;
var t,n:longint;
begin
clrscr;
write('Nhap thang, nam: ');readln(t,n);
if t in [1,3,5,7,8,10,12] then writeln('Thang ',t,' co 31 ngay')
    else
    if t in [4,6,9,11] then writeln('Thang ',t,' co 30 ngay')
        else
            if (n mod 400=0) or (n mod 4=0) and (n mod 100<>0) then writeln('Thang ',t,' co 29 ngay')
                else writeln('Thang ',t,' co 30 ngay');
readln;
end.
