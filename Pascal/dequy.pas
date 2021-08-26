uses crt;

var a,n:longint;
///////////////////////////////////////////////////
function mu(a,n:longint):longint;
begin
if n=0 then mu:=1
    else mu:=a*mu(a,n-1);
end;
///////////////
function f(a,n:longint):longint;
begin



end;
///////////////////////////////////////////////////
begin
clrscr;
readln(a,n);
writeln(mu(a,n),);
readln
end.
