var a:int64;
///////////////////////////////////////
function nto(a:int64):boolean;
var i:longint;
    begin
    if (a < 2) then
        exit(false);
    if (a in [2,3,5,7]) then
        exit(true);
    if (not (a mod 6 in [1,5])) or (a mod 2 = 0) then
        exit(false);
    nto := true;
    i := 3;
    while (i <= trunc(sqrt(a))) do
        begin
        if (a mod i = 0) then
            exit(false);
        i := i + 2;
        end;
    end;
///////////////////////////////////////
begin
readln(a);
while (a <> 0) do
    begin
    if (nto(a)) then
        writeln(a);
    a := a div 10;
    end;
end.