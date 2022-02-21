var d:array[1..2] of longint;
    a,i,n,t:longint;
///////////////////////////////////////
function max(a,b:longint):longint;
    /////////////////
    begin
    if (a > b) then
        exit(a);
    exit(b);
    end;
///////////////////////////////////////
function min(a,b:longint):longint;
    /////////////////
    begin
    if (a < b) then
        exit(a);
    exit(b);
    end;
///////////////////////////////////////
begin
readln(n);
for i := 1 to n do
    begin
    read(a);
    d[a] := d[a] + 1;
    end;
t := min(d[1],d[2]);
t := t + max(0,d[1] - d[2]) div 3;
writeln(t);
end.