var a,k,i:longint;

begin
assign(input,'codeforces_wrongsub.inp');reset(input);
assign(output,'codeforces_wrongsub.out');rewrite(output);
readln(a,k);
for i:=1 to k do
    if a mod 10<>0 then
        a:=a-1
    else
        a:=a div 10;
writeln(a);
end.