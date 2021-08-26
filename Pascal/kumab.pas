var a,b:int64;

begin
assign(input,'kumab.inp');reset(input);
assign(output,'kumab.out');rewrite(output);
readln(a);
b:=a;
while a div 10<>0 do
    a:=a mod 10+(a div 10)*3;
writeln(a+b);
end.