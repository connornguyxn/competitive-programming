var a:ansistring;a2,b:int64;i,kt:longint;

begin
assign(input,'socuoi.inp');reset(input);
assign(output,'socuoi.out');rewrite(output);
readln(a);
while length(a)<>1 do
    begin
    b:=1;
    for i:=1 to length(a) do
        begin
        val(a[i],a2,kt);
        b:=b*a2;
        end;
    str(b,a);
    end;
writeln(a)
end.
