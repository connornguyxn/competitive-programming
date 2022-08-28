var a:ansistring;
////////////////////
function tcs(a:ansistring):int64;
var i,e:longint;c:int64;
begin
tcs:=0;
for i:=1 to length(a) do
    begin
    val(a[i],c,e);
    tcs:=tcs+c;
    end;
end;
/////////////////////
begin
readln(a);
writeln(tcs(a));
end.