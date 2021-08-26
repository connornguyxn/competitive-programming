var l:array[1..3] of int64;

begin
assign(input,'ucode_div3.inp');reset(input);
assign(output,'ucode_div3.out');rewrite(output);
readln(n);
for i:=1 to n do
    begin
    read(a);
    a:=a mod 3;
    if a=0 then
        d0:=d0+1
    else
        begin
        l[a]:=l[a]+1;
        d:=d+l[3-a];
        end;
    end;
end.