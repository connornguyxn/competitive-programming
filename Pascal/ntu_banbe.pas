uses crt;
var a,b,i,t:longint;
//////////////////////////////////////
function uoc(a:longint):longint;
begin
for i:=1 to a do
    begin
    if a mod i=0 then uoc:=uoc+i;
    end;
end;
//////////////////////////////////////
begin
clrscr;
readln(a,b);
if (uoc(a)=b) and (uoc(b)=a) then writeln('YES');
   // else writeln('NO');
readln
end.