var a,d,bak:array[0..100000] of longint;
    i,n,k,test,tests:longint;
///////////////////////////////////////
begin
assign(input,'ucode_average.inp');reset(input);
readln(tests);
for test := 1 to tests do
    begin
    d := bak;
    readln(n,k);
    for i := 1 to n do
        begin
        read(a[i]);
        d[a[i]] := d[a[i]] + 1;
        end;
    for i := 1 to n do
        write(d[(a[i] + k) div 2],' ');
    writeln();
    end;
end.