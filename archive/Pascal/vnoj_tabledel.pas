var xs,ys:array[0..100000] of longint;
    i,m,n,x,y,k,d:longint;
///////////////////////////////////////
begin
//assign(input,'vnoj_tabledel.inp');reset(input);
readln(n,m,k);
if (k = 1) then
    begin
    writeln(1);
    halt;
    end;
for i := 1 to k do
    begin
    readln(x,y);
    xs[x] := xs[x] + 1;
    ys[y] := ys[y] + 1;
    end;
d := 0;
for i := 1 to n do
    begin
    if ((xs[i] = m) or (xs[i] = 0)) then
        d := d + 1;
    end;
n := n - d;
d := 0;
for i := 1 to m do
    begin
    if ((ys[i] = n) or (ys[i] = 0)) then
        d := d + 1;
    end;
m := m - d;
writeln(n * m);
end.