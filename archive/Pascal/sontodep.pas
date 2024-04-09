var n:longint;
    c:array[1..4] of char = ('2', '3', '5', '7'); 
///////////////////////////////////////
function tostr(a:int64):ansistring;
    /////////////////
    begin
    str(a,tostr);
    end;
///////////////////////////////////////
function toint(a:ansistring):int64;
    /////////////////
    begin
    val(a,toint);
    end;
///////////////////////////////////////
function isprime(a:int64):boolean;
    var i:longint;
    /////////////////
    begin
    if (a < 2) then
        exit(false);
    if (a in [2,3,5,7]) then
        exit(true);
    if (a mod 2 = 1) then
        exit(false);
    i := 3;
    while (i <= trunc(sqrt(a))) do
        begin
        if (a mod i = 0) then
            exit(false);
        i := i + 2;
        end;
    exit(true);
    end;
///////////////////////////////////////
function count(n:ansistring; mx:longint):longint;
    var i:longint;
    /////////////////
    begin
    count := 0;
    if (length(n) > 0) then
        begin
        if (length(n) > length(tostr(mx))) then
            exit(0);
        if (toint(n) > mx) then
            exit(0);
        if (isprime(toint(n))) then
            count := count + 1;
        end;
    for i := 1 to 4 do
        count := count + count(n + c[i], mx);
    end;
///////////////////////////////////////
begin
readln(n);
writeln(count('', n));
end.