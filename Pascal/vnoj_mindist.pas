var p:array[1..1000000] of longint;
    i,n,mn,a:longint;
///////////////////////////////////////
begin
assign(input,'vnoj_mindist.inp');reset(input);
assign(output,'vnoj_mindist.out');rewrite(output);
readln(n);
mn := n;
for i := 1 to n do
    begin
    read(a);
    if ((p[a] > 0) and (i - p[a] < mn)) then
        mn := i - p[a];
    p[a] := i;
    end;
if (mn = n) then
    writeln(-1)
else
    writeln(mn);
end.