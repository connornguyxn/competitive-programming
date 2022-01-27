function dectobasen(a,n:int64):ansistring;
var c:ansistring;
begin
dectobasen:='';
while a<>0 do
    begin
    str((a mod k),c);
    dectobasen:=c+dectobasen;
    a:=a div k;
    end;
end;
