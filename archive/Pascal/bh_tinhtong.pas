var n,m,r:int64;
    k,i:longint;
///////////////////////////////////////
function mu(a,b:int64):int64;
    var k,h:int64;
    //////////////////////
    begin
    if (b = 1) then
        exit(a mod m);
    k := b div 2;
    h := a * a mod m;
    if (b mod 2 = 0) then
        exit(mu(h,k) mod m)
    else 
        exit((mu(h,k) mod m) * a mod m);
    end;
///////////////////////////////////////
begin
readln(n,k,m);
for i := 1 to (k div 2) do
    begin
    t := t + mu(i,i)
    end;
end.