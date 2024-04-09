var a,i,n,m:longint;
//////////////////////////////////////////
begin
//assign(input,'ntu_tile.inp');reset(input);
//assign(output,'ntu_tile.out');rewrite(output);
readln(n);
read(m);
for i:=1 to n-1 do
    begin
    read(a);
    if a>m then m:=a;
    end;
if m+1>=n then
    writeln(m+1)
else writeln(n)
end.
