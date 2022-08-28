function rev(a:ansistring):ansistring;
var i,kt:longint;
begin
for i:=1 to length(a) do
    rev:=a[i]+rev;
end;