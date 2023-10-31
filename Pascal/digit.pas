var i,d:longint;
a,b:longint;
////////////////////////////func//////////////////////////////
function nto(a:longint):boolean;
begin
i:=1;
if a<2 then exit(false);
if a in [2,3,5,7] then exit(true);
if a mod 2=0 then exit(false);
nto:=true;
while i<=trunc(sqrt(a)) do
    begin
    i:=i+2;
    if a mod i=0 then exit(false);
    end;
end;
///////////////////////////////////
function dx(anum:longint):boolean;
var i:longint;a:ansistring;
begin
str(anum,a);
dx:=true;
for i:=1 to length(a) div 2 do
if a[i]<>a[length(a)-i+1] then exit(false);
end;
/////////////////////////main////////////////////////////////
begin
readln(a,b);
for i:=a to b do
    if (nto(i)=true) and (dx(i)=true) then
        d:=d+1;
writeln(d);
end.
