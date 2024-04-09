type boolar = array[0..100000000] of boolean;
var nto:boolar;
    l,r,d:longint;
//////////////////////////////////////////
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
    i := 1;
    while (i <= trunc(sqrt(a))) do
        begin
        i := i + 2;
        if (a mod i = 0) then
            exit(false);
        end;
    end;
/////////////////
procedure sangnto(var a:boolar);
var i,j:longint;
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
////////////////////////////////////////////
begin
sangnto(nto);
readln(l,r);
d := 0;
for l:=l to r do
    begin
    if (nto[l] = true) then
        d := d + 1;
    end;
writeln(d);
end.
