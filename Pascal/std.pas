unit std;
///////////////////////////////////////
interface
type intar = array[0..1000000] of int64;
    boolar = array[0..1000000] of boolean;
function factorcnt(n:longint):longint;
function pow(a,n:int64):int64;
function gcd(a,b:int64):int64;
function lcm(a,b:int64):int64;
function isprime(a:longint):boolean;
procedure init_sieve(var isprime:boolar);
procedure qsort(var a:intar;l,r:longint);
///////////////////////////////////////
implementation
function factorcnt(n:longint):longint;
    var i:longint;
    /////////////////
    begin
    if (n = 1) then
        exit(1);
    factorcnt := 1;
    for i := 1 to (trunc(sqrt(n))) do
        begin
        if (n mod i = 0) then
            factorcnt := factorcnt + 1;
        end;
    end;
///////////////////////////////////////
function pow(a,n:int64):int64;
    var k,h:int64;
    /////////////////
    begin
    if (n = 1) then
        exit(a);
    k := n div 2;
    h := a * a;
    if (n mod 2 = 0) then
        exit(pow(h,k))
    else 
        exit((pow(h,k) * a));
    end;
///////////////////////////////////////
function gcd(a,b:int64):int64;
    var r:int64;
    /////////////////
    begin
    while (b <> 0) do
        begin
        r := a mod b;
        a := b;
        b := r;
        end;
    gcd := a;
    end;
///////////////////////////////////////
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
///////////////////////////////////////
function isprime(a:longint):boolean;
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
procedure init_sieve(var isprime:boolar);
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
function binsearch(k,l,r:longint;a:intar):boolean;
    var m:longint;
    /////////////////
    begin
    while (l <= r) do
        begin
        m := (l + r) div 2;
        if (k < a[m]) then
            r := m - 1
        else if (k > a[m]) then
            l := m + 1
        else
            exit(true);
        end;
    exit(false);
    end;
///////////////////////////////////////
procedure qsort(var a:intar;l,r:longint);
    var i,j,x,tg:longint;
    /////////////////
    begin
    i := l;
    j := r;
    x := a[(l + r) div 2];
    while (i <= j) do
        begin
        while (a[i] < x) do
            i := i + 1;
        while (a[j] > x) do
            j := j - 1;
        if (i <= j) then
            begin
            tg := a[i];
            a[i] := a[j];
            a[j] := tg;
            i := i + 1;
            j := j - 1;
            end;
        end;
    if (i < r) then
        qsort(a,i,r);
    if (j > l) then
        qsort(a,l,j);
    end;
///////////////////////////////////////
end.