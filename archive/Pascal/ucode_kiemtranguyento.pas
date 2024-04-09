var a,n,i:longint;
///////////////////////////////////////
function nto(a:longint):longint;
var i:longint;
    begin
    if (a < 2) then
        exit(0);
    if (a in [2,3,5,7]) then
        exit(1);
    if (a mod 2 = 0) then
        exit(0);
    i := 3;
    while (i <= trunc(sqrt(a))) do
        begin
        if (a mod i = 0) then
            exit(0);
        i := i + 2;
        end;
    exit(1);
    end;
///////////////////////////////////////
begin
readln(n);
for i := 1 to n do
    begin
    read(a);
    write(nto(a),' ');
    end;
end.