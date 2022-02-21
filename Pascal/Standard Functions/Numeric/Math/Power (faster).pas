function pow(n,k:qword):qword;
    /////////////////
    begin
    pow := 1;
    while (k > 0) do
        begin
        if (k mod 2 = 1) then
            pow := pow * n;
        pow := sqr(pow);
        k := k div 2;
        end;
    end;