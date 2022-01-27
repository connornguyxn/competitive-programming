var k:int64;
///////////////////////////////////////
function mu(a,b,d:int64):int64;
    var k,h:int64;
    //////////////////////
    begin
    if (b = 1) then
        exit(a mod d);
    k := b div 2;
    h := a * a mod d;
    if (b mod 2 = 0) then
        exit(mu(h,k,d) mod d)
    else 
        exit((mu(h,k,d) mod d) * a mod d);
    end;
///////////////////////////////////////
begin
readln(k);
writeln(mu(2,k,k));
end.