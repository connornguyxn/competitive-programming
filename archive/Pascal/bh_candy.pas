var n,m,avg,mn,mx:int64;
///////////////////////////////////////
begin
//assign(input,'bh_candy.inp');reset(input);
//assign(output,'bh_candy.out');rewrite(output);
readln(n,m);
if (((n + 1) * n) div 2 > m) then
    begin
    writeln(-1);
    halt;
    end;
avg := m div n;
mn := avg - (n div 2);
mx := avg + (n div 2);
if (m mod n > 0) then
    mx := mx + 1;
writeln(mn,' ',mx);
end.