var a:array[0..100000000] of longint;
    l,r,i,n,mx,test,tests:longint;
///////////////////////////////////////
begin
//assign(input,'ntu_games.inp');reset(input);
//assign(output,'ntu_games.out');rewrite(output);
readln(n,tests);
for i:=1 to (n - 1) do
    read(a[i]);
readln(a[n]);
for test:=1 to tests do
    begin
    readln(l,r);
    r := l + r - 1;
    mx := 0;
    for i:=l to r do
        begin
        if (a[i] > mx) then
            mx := a[i];
        end;
    writeln(mx + 1);
    for i:=l to r do
        a[i] := mx + 1;
    end;
end.