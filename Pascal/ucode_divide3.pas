var n,a,b,d,i:longint;

begin
assign(input,'ucode_divide3.inp');reset(input);
assign(output,'ucode_divide3.out');rewrite(output);
readln(n,a,b);
for i:=1 to n do
    begin
    if (i mod a=0) or (i mod b=0) then
        d:=d+1;
    end;
writeln(d);
end.