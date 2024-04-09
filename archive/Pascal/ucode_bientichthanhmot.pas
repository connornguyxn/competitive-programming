var a,i,n:longint;
    t:qword;
    d:array[-1..1] of longint;
///////////////////////////////////////
begin
//assign(input,'ucode_bientichthanhmot.inp');reset(input);
readln(n);
for i := 1 to n do
    begin
    read(a);
    if (a = 0) then
        d[0] := d[0] + 1
    else
        begin
        d[a div abs(a)] := d[a div abs(a)] + 1;
        t := t + abs(a) - 1;
        end;
    end;
t := t + d[0];
d[-1] := d[-1] mod 2;
if ((d[-1] = 1) and (d[0] = 0)) then
    t := t + 2;
writeln(t);
end.