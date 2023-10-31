var a,n,t,i:longint;

begin
assign(input,'hinhphat.inp');reset(input);
assign(output,'hinhphat.out');rewrite(output);
readln(n);
for i:=1 to n do
    begin
    read(a);
    if a=1 then t:=t+1
        else t:=t-1;
    end;
writeln(abs(t));
end.
