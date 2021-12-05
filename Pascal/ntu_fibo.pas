function mu(a:extended; n:longint):extended;
var i:longint;
begin
    mu:=1;
    for i:=1 to n do
        mu:=mu*a;
end;
/////////////////////////////
function binet(n:longint):extended;
var phi,psi:extended;
begin
    phi := (1 + sqrt(5)) / 2;
    psi := (1 - sqrt(5)) / 2;
   exit((mu(phi, n) - mu(psi, n)) / sqrt(5));
end;
///////////////////////////
var n,i:longint;

begin
readln(n);
for i:=1 to n-1 do
    write(binet(i):0:0,' ');
writeln(binet(n):0:0);
end.