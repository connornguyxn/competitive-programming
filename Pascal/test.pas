function mu(a:real; n:longint):real;
var i:longint;
begin
    mu:=1;
    for i:=1 to n do
        mu:=mu*a;
end;
/////////////////////////////
function binet(n:longint):longint;
var phi,psi:real;
begin
    phi:= (1 + sqrt(5)) / 2;
    psi:= (1 - sqrt(5)) / 2;
    exit(round((mu(phi,n) - mu(psi,n)) / sqrt(5)));
end;

///////////////////////////
var n:longint;
begin
readln(n);
writeln(binet(n));
end.