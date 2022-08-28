var n,i,a:longint;t:int64;
/////////////////////////////
begin
assign(input,'tbc.inp');reset(input);
assign(output,'tbc.out');rewrite(output);
readln(n);
for i:=1 to n do
    begin
    read(a);
    t:=t+a;
    end;
writeln(t/a:0:2);
writeln(t div a);
end.