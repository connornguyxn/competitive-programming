function gt(a:int64):int64;
var i:longint;
begin
gt:=1;
for i:=1 to a do
    gt:=gt*i
end;