var a:ansistring;n,b,t:int64;i,kt:longint;

begin
assign(input,'sumdownto.inp');reset(input);
assign(output,'sumdownto.out');rewrite(output);
readln(a);
readln(n);
for i:=length(a)-1 to length(a) do
    begin
    val(a[i],b,kt);
    t:=t+b;
    end;
writeln(t)
end.