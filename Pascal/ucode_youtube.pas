var a,b:int64;

begin
assign(input,'ucode_youtube.inp');reset(input);
assign(output,'ucode_youtube.out');rewrite(output);
readln(a);
b:=10;
while a>=b do
    b:=b*10;
writeln(b-a);
end.