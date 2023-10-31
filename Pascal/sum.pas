var a:ansistring;k,b,t:qword;i,kt:longint;

begin
assign(input,'sum.inp');reset(input);
assign(output,'sum.out');rewrite(output);
readln(a);
readln(k);
t:=0;
for i:=length(a)-k+1 to length(a) do
    begin
    val(a[i],b,kt);
    t:=t+b;
    end;
writeln(t);
end.

