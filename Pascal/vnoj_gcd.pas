var a:array[0..1000000] of longint;
    b,i,n,m,res:longint;
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
begin
readln(n,m);
read(a[1]);
g := 1;
for i := 2 to n do
    begin
    read(a[i]);
    g := gcd(g,a[i] - a[i - 1]);
    end;
for i := 1 to m do
    begin
    read(b);
    writeln(gcd(g,b + a[i]));
    end;
end.