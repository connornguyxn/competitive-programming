var d,n,m:longint;

begin
assign(input,'ntu_tigu.inp');reset(input);
assign(output,'ntu_tigu.out');rewrite(output);
readln(n,m);
d:=0;
while n<m do
    begin
    d:=d+1;
    n:=n+round(n/10);
    end;
writeln(d);
end.