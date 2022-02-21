var n:longint;
///////////////////////////////////////
function pow(a:extended; n:longint):extended;
    var i:longint;
    /////////////////
    begin
    pow := 1;
    for i := 1 to n do
        pow := pow * a;
    end;
/////////////////////////////
function binet(n:longint):extended;
    var phi,psi:extended;
    /////////////////
    begin
    phi := (1 + sqrt(5)) / 2;
    psi := (1 - sqrt(5)) / 2;
    exit((mu(phi, n) - mu(psi, n)) / sqrt(5));
    end;
///////////////////////////
begin
readln(n);
writeln(binet(n):0:0);
end.