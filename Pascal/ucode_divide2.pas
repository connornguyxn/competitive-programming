var n,i,d:int64;

begin
assign(input,'ucode_divide2.inp');reset(input);
assign(output,'ucode_divide2.out');rewrite(output);
readln(n);
i:=0;
while i<=n do
    begin
    if i mod 3=0 then
        d:=d+1;
    i:=i+1
    end;
writeln(d+((n-(n mod 2)) div 2)+1);
end.