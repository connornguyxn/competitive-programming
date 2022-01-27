function dx(a:ansistring):boolean;
var i:longint;
begin
dx:=true;
for i:=1 to length(a) div 2 do
    if a[i]<>a[length(a)-i+1] then
        exit(false);
end;