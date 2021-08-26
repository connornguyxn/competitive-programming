var t,a:int64;
i:longint;

begin
assign(input,'hoha2.inp');reset(input);
assign(output,'hoha2.out');rewrite(output);
readln(a);
for i:=2 to trunc(sqrt(a)) do
    if a mod i=0 then writeln(i);
if t+1=a then writeln('YES')
    else writeln('NO');
end.
