type boolar = array[1..2000000] of boolean;
var nto:boolar;
    i,n,m,t:longint;
///////////////////////////////////////
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
        for j := 2 to (sizeof(a) div i) do
            a[i * j] := false;
        i := i + 1;
        end;
    end;
///////////////////////////////////////
function max(a,b:longint):longint;
    /////////////////
    begin
    if (a > b) then
        exit(a);
    exit(b);
    end;
///////////////////////////////////////
begin
//assign(input,'vnoj_flowers.inp');reset(input);
sangnto(nto);
readln(n,m);
if (n > m) then
    begin
    i := n;
    n := m;
    m := i;
    end;
for i := 1 to n do
    begin
    if (nto[i + 1]) then
        begin
        //writeln('+ ',i);
        t := t + i;
        end;
    end;
for i := (n + 1) to m do
    begin
    if (nto[i + 1]) then
        begin
        //writeln('+ ',i - (i - n));
        t := t + i - (i - n);
        end;
    end;
for i := (m + 1) to (m * 2 - 1) do
    begin
    if (nto[i + 1]) then
        begin
        //writeln('i = ',i,' | + ',i - (i - n) - (i - m));
        if (i - (i - n) - (i - m) < 1) then
            break;
        t := t + i - (i - n) - (i - m);
        end;
    end;
writeln(t);
end.
