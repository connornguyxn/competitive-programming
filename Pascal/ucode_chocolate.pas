var a,b:int64;
/////////////////////////////////////////////////////
begin
assign(input,'ucode_chocolate.inp');reset(input);
assign(output,'ucode_chocolate.out');rewrite(output);
readln(a,b);
while true do
    begin
    if a<b then
        b:=b-a
    else
        a:=a-b;
    if (a=b) or (a=0) or (b=0) then
        break;
    end;
writeln(a+b)
end.
