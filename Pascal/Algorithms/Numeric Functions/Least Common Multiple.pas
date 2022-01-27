function bcnn(a,b:int64):int64;
var r:int64;
begin
bcnn:=a*b;
while b<>0 do
    begin
    r:=a mod b;
    a:=b;
    b:=r;
    end;
bcnn:=bcnn div a;
end;

