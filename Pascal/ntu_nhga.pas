var i,n:longint;
a,b,min:int64;

begin
assign(input,'nhga.inp');reset(input);
assign(output,'nhga.out');rewrite(output);
readln(n);
min:=1;
for i:=1 to n do
    begin
    if i=2 then min:=abs(b-a);
    if i=1 then
        read(a)
    else
        begin
        read(b);
        if abs(b-a)<min then min:=abs(b-a);
        a:=b
        end;
    end;
writeln(min)
end.