var a:array[1..100000000] of longint;
i,n,c:longint;
begin
assign(input,'ezsort.inp');reset(input);
assign(output,'ezsort.out');rewrite(output);
readln(c);
n:=c;
for i:=1 to c do
    readln(a[i]);
for i:=c downto 1 do
    if a[i]=n then n:=n-1;
writeln(n);
end.