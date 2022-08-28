var a,m,n,t,sum:qword;i:longint;

begin
assign(input,'trochoi.inp');reset(input);
assign(output,'trochoi.out');rewrite(output);
readln(n,t,m);
for i:=1 to n do
    begin
    read(a);
    if i in [t..t+m] then
        begin
        sum:=sum+a;
        end;
    end;
writeln(sum)
end.
