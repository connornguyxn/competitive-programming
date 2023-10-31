var i,j,n,d:longint;
a:array[1..100000000] of longint;
//////////////////////////////////
begin
assign(input,'ntu_caso.inp');reset(input);
assign(output,'ntu_caso.out');rewrite(output);
readln(n);
for i:=1 to n do
    read(a[i]);
for i:=1 to n-1 do
    begin
    for j:=i+1 to n do
        if a[i]=a[j] then
            begin
            d:=d+1;
            end;
    end;
writeln(d);
end.
