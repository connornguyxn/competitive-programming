function pow(a:int64; n:longint):int64;
    var i:longint;
    /////////////////
    begin
    pow := 1;
    for i := 1 to n do
        pow := pow * a;
    end;