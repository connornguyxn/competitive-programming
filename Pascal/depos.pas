var a,b,x,t:real;

begin
assign(input,'depos.inp');reset(input);
assign(output,'depos.out');rewrite(output);
read(a,b,x);
t:=(a-b)/(a*x/100);
if trunc(t)<>0 then t:=round(t)+1;
writeln(t);
end.
