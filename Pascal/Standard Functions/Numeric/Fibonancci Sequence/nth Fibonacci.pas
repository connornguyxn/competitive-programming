function nfib(n:longint):int64;
    var f1,fn:int64;
        i:longint;
    /////////////////
    begin
    if (n = 1) then
        exit(0);
    if (n = 2) then
        exit(1)
    f1 := 0;
    fn := 1;
    for i := 1 to n do
        begin
        fn := f1 + fn;
        f1 := fn - f1;
        end;
    exit(fn);
    end;