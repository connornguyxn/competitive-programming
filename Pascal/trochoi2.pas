var a:array[1..100000000] of int64;m,n,t,sum:int64;i:longint;

begin
assign(input,'trochoi.inp');reset(input);
assign(output,'trochoi.out');rewrite(output);
readln(n,t,m);
sum:=0;
for i:=1 to n do read(a[i]);
for i:=t to t+m-1-n do sum:=sum+a[i];
writeln(sum)
end.
