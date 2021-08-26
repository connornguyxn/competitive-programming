function convtok(a,k:int64):ansistring;
var c:ansistring;
begin
convtok:='';
while a<>0 do
    begin
    str((a mod k),c);
    convtok:=c+convtok;
    a:=a div k;
    end;
end;
/////////////////////////
begin
writeln(convtok(100,9));
readln;
end.
