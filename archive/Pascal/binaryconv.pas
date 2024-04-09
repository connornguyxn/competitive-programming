var a:int64;
//////////////////////////
function bin(a:int64):ansistring;
var c:ansistring;
begin
bin:='';
if a=0 then
    exit('0');
while a<>0 do
    begin
    str((a mod 2),c);
    bin:=c+bin;
    a:=a div 2;
    end;
end;
/////////////////////////
begin
readln(a);
writeln(bin(a));
end.
