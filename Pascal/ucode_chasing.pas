var a,b,c,d,i,j:longint;

begin
assign(input,'ucode_chasing.inp');reset(input);
assign(output,'ucode_chasing.out');rewrite(output);
i:=1;
j:=1;
readln(a,b);
readln(c,d);
while b+a*i<>d+c*j do
    begin
    i:=i+1;
    j:=j+1;
    if i>100 or j>100 then
        begin
        writeln(-1);


        end;
    end;
writeln(i,j);
end.
