var d,n,a,i:longint;
/////////////////////////////////////////////
begin
assign(input,'zeronum.inp');reset(input);
assign(output,'zeronum.out');rewrite(output);
readln(n);
d:=0;
for i:=1 to n do
    begin
    a:=i;
    while a mod 5=0 do
        begin
        d:=d+1;
        a:=a div 5
        end;
    end;
writeln(d);
end.