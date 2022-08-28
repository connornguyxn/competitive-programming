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
<<<<<<< HEAD
writeln((binet(n) div 1000007):0:0);
=======
writeln(binet(n):0:0);
>>>>>>> ff1e4424a3963b8bde9665cede1359df7d8c8746
end.