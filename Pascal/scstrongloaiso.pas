uses crt;
var i,d,a,n,k:longint;
ix,kx:ansistring;
/////////////////////////////
function mu(a,b:int64):int64;
var i:longint;
begin
mu:=1;
for i:=1 to b do
    mu:=mu*a
end;
////////////////////////////
begin
clrscr;
readln(a,k);
str(k,kx);
//for i:=mu(10,n-1) to mu(10,n)-1 do
for i:=1 to a do
    begin
    str(i,ix);
    if pos(kx,ix)<>0 then
        d:=d+1;
    end;
writeln(d);
readln
end.