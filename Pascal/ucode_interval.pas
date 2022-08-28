var l,r,a,b,t:int64;
x:ansistring;

begin
assign(input,'ucode_interval.inp');reset(input);
assign(output,'ucode_interval.out');rewrite(output);
readln(l,r);
a:=1;
b:=1;
while a<=l do
    a:=a*10;
while b<r do
    b:=b*10;
b:=b div 10;
//writeln(a,' ',b);
//t:=t+((b-a) div 10);
str(l,x);
val(x[1],t);
//writeln(l);
writeln(t);
end.

