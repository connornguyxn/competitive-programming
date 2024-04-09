var a:array[0..100000000] of longint;
    i,n,k,t:longint;
///////////////////////////////////////
function min(a,b:longint):longint;
    begin
    if (a < b) then
        exit(a)
    else
        exit(b);
    end;
///////////////////////////////////////
begin
readln(n,k);
for i:=1 to n do
    read(a[i]);
a[0] := 0;
for i:=1 to (n + 1) do
    begin
    t := t + min(a[i-1],k);
    t := t + min(a[i],k - min(a[i-1],k));
    a[i] := a[i] - min(a[i],k - min(a[i-1],k));
    //write(a[i],' ');
    end;
writeln(t);
end.