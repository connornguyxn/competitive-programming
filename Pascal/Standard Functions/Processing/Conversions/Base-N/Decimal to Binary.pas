function bin(a:int64):ansistring;
    var b:ansistring;
    ////////////////
    begin
    bin:=0;
    while (a <> 0) do 
        begin
        str((a mod 2),b);
        bin := b + bin;
        a := a div 2;
        end;
    end;