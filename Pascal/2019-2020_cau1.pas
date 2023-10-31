var i,k,n,t:longint;

begin
assign(input, '2019_2020_cau1.inp');reset(input);
assign(output, '2019_2020_cau1.out');rewrite(output);
readln(n);;
k:=2;
while (k+1)*k div 2<=n do
    k:=k+1;
k:=k-1;
n:=n-((k+1)*k div 2);
writeln(n);
writeln(k);
end.
