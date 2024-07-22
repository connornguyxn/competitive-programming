function lcm(a,b:int64):int64;
    var r:int64;
    /////////////////
    begin
    lcm := a * b;
    while (b <> 0) do
        begin
        r := a mod b;
        a := b;
        b := r;
        end;
    lcm := lcm div a;
    end;