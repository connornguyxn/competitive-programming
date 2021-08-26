var n,i,j:longint;

begin
assign(input,'tgvu.inp');reset(input);
assign(output,'tgvu.out');rewrite(output);
readln(n);
for i:=n downto 1 do
    begin
    for j:=1 to i do
        begin
        write('*');
        end;
    writeln();
    end;
end.