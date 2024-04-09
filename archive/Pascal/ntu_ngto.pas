type boolar = array[0..10000000] of boolean;
var nto:boolar;
    n:longint;
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
        n := n - 1;
        if (n = 0) then
            begin
            writeln(i);
            halt;
            end;
        for j:=2 to (sizeof(a) div i) do
            a[i * j] := false;
        i := i + 1;
        end;
    while (i <= sizeof(a)) do
        begin
        while (a[i] = false) do
            i := i + 1;
        n := n - 1;
        if (n = 0) then
            begin
            writeln(i);
            halt;
            end;
        end;
    end;
////////////////////////////////////////////
begin
readln(n);
sangnto(nto);
end.