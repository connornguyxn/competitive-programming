var n,i:longint;
t:qword;

begin
assign(input,'ucode_square.inp');reset(input);
assign(output,'ucode_square.out');rewrite(output);
readln(n);
for i:=1 to n do
    t:=t+i*i;
writeln(t mod 1000000007);
end.

