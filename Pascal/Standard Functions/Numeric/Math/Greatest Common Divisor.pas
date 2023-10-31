function gcd(a,b:int64):int64;
    var r:int64;
    /////////////////
    begin
    while (b <> 0) do
        begin
        r := a mod b;
        a := b;
        b := r;
        end;
    gcd := a;
    end;