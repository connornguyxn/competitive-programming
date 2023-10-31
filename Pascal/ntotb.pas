var t:qword;
a,b,i,d:longint;
//vi bai thi cho so be hon 10^7 nen em moi lam ntn
///////////////////function///////////////
function nto (a:longint):boolean;
var i:longint;
begin
if a<2 then exit(false);
if a in [2,3,5,7] then exit(true);
if a mod 2=0 then exit(false);
nto:=true;
i:=1;
while i<= trunc(sqrt(a)) do
    begin
    i:=i+2;
    if a mod i=0 then exit(false);
    end;
end;
//////////////ct chinh/////////////////////
begin
read(a,b);
d:=0;t:=0;
for i:=a to b do
    if nto(i)=true then
        begin
        t:=t+i;
        d:=d+1;
        end;
writeln(t/d:0:2);
end.