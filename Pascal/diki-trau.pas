var a:array[1..100000000] of int64;
i,j,n,m:longint;

begin
assign(input,'diki.inp');reset(input);
assign(output,'diki.out');rewrite(output);
readln(n,m);
for i:=1 to n do read(a[i]);
for i:=1 to n-1 do
    for j:=i+1 to n do
        begin
        if a[j]-a[i]=m then
            begin
            writeln(a[i],' ',a[j]);
            halt;
            end;
        end;
writeln(-1);
end.