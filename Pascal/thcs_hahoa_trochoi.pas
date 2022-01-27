type ar = array[1..100000] of longint;
var nto,d:ar;
    a,i,n,n2,j,mx:longint;
//////////////////////////////////////////
procedure gen(var nto:ar; var d:longint);
    var i,j:longint;
    snto:array[1..100000] of boolean;
    /////////////////
    begin
    d := 0;
    fillchar(snto,sizeof(snto),true);
    snto[1] := false;
    i := 2;
    while (i <= trunc(sqrt(sizeof(snto)))) do
        begin
        while (snto[i] = false) do
            i := i + 1;
        d := d + 1;
        nto[d] := i;
        for j := 2 to (sizeof(snto) div i) do
            snto[i * j] := false;
        i := i + 1;
        end;
    end;
///////////////////////////////////////
begin
assign(input,'thcs_hahoa_trochoi.inp');reset(input);
gen(nto,n2);
readln(n);
mx := 0;
for i := 1 to n do
    begin
    read(a);
    for j := 1 to n2 do
        begin
        if (a mod nto[j] = 0) then
            begin
            d[nto[j]] := d[nto[j]] + 1;
            if (d[nto[j]] > mx) then
                mx := d[nto[j]];
            end;
        end;
    end;
writeln(mx);
end.
