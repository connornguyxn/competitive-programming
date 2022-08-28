var a,up:ansistring;
i,d:longint;
begin
assign(input,'cfword.inp');reset(input);
assign(output,'cfword.out');rewrite(output);
up:='ABCDEFGHIKLMNOPQRSTUVWXYZ';
readln(a);
for i:=1 to length(a) do
    if pos(a[i],up)<>0 then d:=d+1;
if d>length(a)-d then
    writeln(upcase(a))
else
    writeln(lowercase(a));
end.