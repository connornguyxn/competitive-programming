var c1:array[1..4] of char = ('2','3','5','7');
    c:array[1..4] of char = ('1','3','7','9');
    n,d:longint;
///////////////////////////////////////
function nto(a:int64):boolean;
    var i:longint;
    /////////////////
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
function cint(a:string):int64;
    var check:longint;
    /////////////////
    begin
    val(a,cint,check);
    end;
///////////////////////////////////////
procedure try(a:string;k:longint);
    var i:longint;
    /////////////////
    begin
    writeln(a);
    if (k = 1) then
        begin
        for i := 1 to 4 do
            try(a + c1[i],k + 1);
        end
    else
        begin
        if (not (nto(cint(a)))) then
            exit();
        if (k = n + 1) then
            d := d + 1
        else
            begin
            for i := 1 to 4 do
                try(a + c[i],k + 1);
            end;
        end;
    end;
///////////////////////////////////////
begin
d := 0;
n := 9;
try('',1);
writeln(d);
end.