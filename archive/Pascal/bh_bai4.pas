var l,r:int64;
    isprime:array[1..1000000] of boolean;
//////////////////////////////////////////
procedure init_sieve();
    var i,j:longint;
    /////////////////
    begin
    fillchar(isprime,sizeof(isprime),true);
    isprime[1] := false;
    i := 2;
    while (i <= trunc(sqrt(sizeof(isprime)))) do
        begin
        while (not isprime[i]) do
            i := i + 1;
        for j := 2 to (sizeof(isprime) div i) do
            isprime[i * j] := false;
        i := i + 1;
        end;
    end;
///////////////////////////////////////
function factorcnt(n:int64):longint;
    var i:longint;
    /////////////////
    begin
    factorcnt := 0;
    for i := 1 to (trunc(sqrt(n)) - 1) do 
        begin
        if (n mod i = 0) then
            factorcnt := factorcnt + 2;
        end;
    if (frac(sqrt(n)) = 0) then
        factorcnt := factorcnt + 1;
    end;
///////////////////////////////////////
procedure subtask1();
    var i,res,fcnt:longint;
    /////////////////
    begin
    init_sieve();
    res := 0;
    for i := l to r do
        begin
        fcnt := factorcnt(i);
        if ((fcnt > 2) and (isprime[fcnt])) then
        //if ((fcnt > 2) and (isprime[fcnt])) then
            res := res + 1;
        end;
    writeln(res);
    end;
///////////////////////////////////////
begin
//assign(input,'bh_bai4.inp');reset(input);
readln(l,r);
//writeln(factorcnt(r));
subtask1();
end.