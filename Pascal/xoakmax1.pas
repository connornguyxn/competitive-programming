

/////////////////////////////////////////
function posmax(a:ansistring):ansistring;
var m,kt,c:longint;
ms:ansistring;
begin
m:=0;
for i:=1 to length(a) do
    begin
    val(a[i],c,kt);
    if c>m then m:=c;
    end;
str(m,ms);
posmax:=pos(ms,a);
end;
//////////////////////////////////////////
begin
readln(a,k);
while k<>0 do
    begin
    y:=copy(a,1,k+1);
    kq:=kq+y[posmax(y)]
    end;
end.