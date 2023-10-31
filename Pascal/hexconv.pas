///////////////////////////////
function hex(a:int64):ansistring;
var char:array[0..5] of string=('A','B','C','D','E','F');
c:ansistring;
begin
hex:='';
while a<>0 do
    begin
    if (a mod 16)<10 then
        begin
        str((a mod 16),c);
        hex:=c+hex;
        end
    else
        hex:=char[(a mod 16)-10]+hex;
    a:=a div 16;
    end;
end;
///////////////////////////////
begin
writeln(hex(16));
readln
end.
