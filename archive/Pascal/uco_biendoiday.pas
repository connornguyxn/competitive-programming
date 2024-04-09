var a,b,d:int64;
    i,n,k:longint;
///////////////////////////////////////
function min(a,b:int64):int64;
    /////////////////
    begin
    if (a < b) then
        exit(a);
    exit(b);
    end;
///////////////////////////////////////
begin
readln(n,k);
d := 0;
for i := 1 to n do
    begin
    read(a);
    b := a div k;
    d := d + min(k * (b + 1) - a, a - k * b);
    end;
writeln(d);
end.