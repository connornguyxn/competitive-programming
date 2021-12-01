var a:ansistring;
    l,r,n,i:longint;
/////////////////////////////////////////
function dx(a:ansistring):boolean;
var i:longint;
begin
dx:=true;
for i:=1 to length(a) div 2 do
    if a[i]<>a[length(a)-i+1] then
        exit(false);
end;
/////////////////////////////////////////
begin
readln(a);
readln(n);
for i:=1 to n do
    begin
    readln(l,r);
    if (dx(copy(a,l,r-l))=true) then
        writeln(1)
    else
        writeln(-1);
    end;
end.