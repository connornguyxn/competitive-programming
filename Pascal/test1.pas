var n,i,d:longint;

begin
assign(input,'test1.inp');reset(input);
assign(output,'test1.out');rewrite(output);
readln(n);
for i:=7 to n do
    if i mod 7=0 then
        d:=d+1;
writeln(d);
end.
