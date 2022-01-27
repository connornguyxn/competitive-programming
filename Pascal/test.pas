type boolar = array[0..1000000000] of boolean;
var snto:boolar;
    i,d:longint;
//////////////////////////////////////////
procedure sangnto(var a:boolar);
    var i,j:longint;
    /////////////////
    begin
    fillchar(a,sizeof(a),true);
    a[1] := false;
    i := 2;
    while (i <= trunc(sqrt(sizeof(a)))) do
        begin
        while (a[i] = false) do
            i := i + 1;
        for j:=2 to (sizeof(a) div i) do
            a[i * j] := false;
        i := i + 1;
        end;
    end;
///////////////////////////////////////
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
sangnto(snto);
writeln(d);
end.
