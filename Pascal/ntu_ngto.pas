var a:qword;

function nto(a:qword):boolean;
var i:longint;
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

begin
readln(a);
if nto(a)=true then write('YES')
    else writeln('NO');
end.

