var n:int64;
//////////////////////////////
function nto(a:int64):boolean;
var i:longint;
begin
if a<2 then
    exit(false);
if a in [2,3,5,7] then
    exit(true);
if a mod 2=0 then
    exit(false);
i:=1;
while i<=trunc(sqrt(a)) do
    begin
    i:=i+2;
    if a mod i=0 then
        exit(false);
    end;
exit(true);
end;
/////////////////////////////
begin
readln(n);
n:=n-1;
while nto(n)<>true do
    n:=n-1;
writeln(n);
end.