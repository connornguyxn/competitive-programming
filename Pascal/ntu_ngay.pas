var d,m,y:longint;
////////////////////////////////////////////////////////
function datecount(m,y:longint):longint;
begin
if m in [1,3,5,7,8,10,12] then
    exit(31);
if m in [4,6,9,11] then
    exit(30);
if (y mod 400=0) or ((y mod 4=0) and (y mod 100<>0)) then
    exit(29);
exit(28);
end;
/////////////////////////////////////////////////////////
begin
assign(input,'ntu_ngay.inp');reset(input);
assign(output,'ntu_ngay.out');rewrite(output);
readln(d,m,y);
d:=d+1;
if d>datecount(m,y) then
    begin
    m:=m+1;
    d:=1;
    end;
if m>12 then
    begin
    y:=y+1;
    m:=1;
    end;
writeln(d,' ',m,' ',y);
end.
