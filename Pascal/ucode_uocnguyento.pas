type boolar = array[0..10000] of boolean;
var nto:boolar;
    i,n,a,test,tests:longint;
    ntos:array[0..1000000] of longint;
//////////////////////////////////////////
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
///////////////////////////////////////
begin
sangnto(nto);
n := 0;
for i := 2 to sizeof(nto) do
    begin
    if (nto[i]) then
        begin
        n := n + 1;
        ntos[n] := i;
        end;
    end;
readln(tests);
writeln(n);
for tests := 1 to tests do
    begin
    readln(a);
    for i := 1 to n do
        begin
        if (a mod ntos[i] = 0) then
            write(ntos[i],' ');
        end;
    writeln();
    end;
end.