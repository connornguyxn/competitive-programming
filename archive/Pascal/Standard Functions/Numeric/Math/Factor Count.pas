function factorcnt(n:int64):longint;
    var i:longint;
    /////////////////
    begin
    factorcnt := 0;
    for i := 1 to (trunc(sqrt(n)) - 1) do 
        begin
        if (n mod i = 0) then
            factorcnt := factorcnt + 2;
        end;
    if (frac(sqrt(n)) = 0) then
        factorcnt := factorcnt + 1;
    end;