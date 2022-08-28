var n,t:qword;
///////////////////
begin
readln(n);
if n<1000 then
    t:=5550*n
else
    if n<2000 then
        t:=5550000+5450*(n-1000)
    else
        if n<3000 then
            t:=11000000+5250*(n-2000)
        else
            t:=16250000+5000*(n-3000);
writeln(t+t div 10);
end.