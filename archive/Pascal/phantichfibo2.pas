var i,n,f:longint;
    fib:array[1..40] of longint;
/////////////////////////
function mu(a:extended; n:longint):extended;
var i:longint;
begin
    mu:=1;
    for i:=1 to n do
        mu:=mu*a;
end;
/////////////////////////////
function binet(n:longint):longint;
var phi,psi:extended;
begin
    phi := (1 + sqrt(5)) / 2;
    psi := (1 - sqrt(5)) / 2;
    exit(trunc((mu(phi, n) - mu(psi, n)) / sqrt(5)));
end;
///////////////////////////
begin
readln(n);
for i:=1 to 40 do
    fib[i]:=binet(i);
while n<>0 do
    begin
    for i:=40 downto 1 do
        if fib[i]<=n then
            begin
            write(fib[i], ' ');
            n:=n-fib[i];
            end;
    end;
end.