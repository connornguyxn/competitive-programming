function fb(k:int64):int64;
var f1,f2:int64;
begin
f1:=1;
f2:=1;
while f1+f2<=k do
    begin
    f2:=f1+f2;
    f1:=f2-f1;
    end;
exit(f2);
end;