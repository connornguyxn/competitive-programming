var a:ansistring;
    d:array[0..1000000] of longint;
    n,m,l,r,i:longint;
///////////////////////////////////////
begin
//assign(input,'ucode_query.inp');reset(input);
readln(n);
readln(a);
for i := 1 to (n - 1) do
    begin
    d[i] := d[i - 1];
    if (a[i] = a[i + 1]) then
        d[i] := d[i] + 1;
    //write(d[i],' ');
    end;
readln(m);
for i := 1 to m do
    begin
    readln(l,r);
    writeln(d[r - 1] - d[l - 1]);
    end;
end.