var i,d:longint;
a,b:qword;
////////////int func////////////
function nto(a:qword):boolean;
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
///////////////
function dx(anum:qword):boolean;
var a:ansistring;
begin
dx:=true;
str(anum,a);
for i:=0 to length(a) div 2 do
    begin
    if a[1+i]<>a[length(a)-i] then exit(false);
    end;
end;
////////////
begin
assign(input,'digit.inp');reset(input);
assign(output,'digit.out');rewrite(output);
read(a,b);
for i:=a to b do
    begin
    if nto(a)=true and dx(a)=true then
        begin
        d:=d+1;
        end;
    end;
writeln(d);
end.