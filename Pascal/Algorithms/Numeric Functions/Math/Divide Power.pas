function mu(a,b:int64):int64;
    var k,h:int64;
    /////////////////
    begin
    if (b = 1) then
        exit(a);
    k := b div 2;
    h := a * a;
    if (b mod 2 = 0) then
        exit(mu(h,k))
    else 
        exit((mu(h,k) * a);
    end;