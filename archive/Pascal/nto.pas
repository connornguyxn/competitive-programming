function nto(a:int64):boolean;
var i:longint;
    begin
    if (a < 2) then
        exit(false);
    if (a in [2,3,5,7]) then
        exit(true);
    if (a mod 2 = 0) then
        exit(false);
    nto := true;
    i := -1;
    while (i <= trunc(sqrt(a))) do
        begin
        i := i + 6;
        if (a mod i = 0) then
            exit(false);
        end;
    end;
///////////////////////////////////////
begin
writeln(nto(9));
end.