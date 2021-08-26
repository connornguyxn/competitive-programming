var a:int64;

begin
assign(input,'vtay.inp');reset(input);
assign(output,'vtay.out');rewrite(output);
readln(a);
a:=a mod 7;
if a=0 then writeln(0,' ',7)
    else
        writeln(a,' ',7-a);
end.
