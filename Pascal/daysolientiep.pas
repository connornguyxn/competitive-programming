var a:array[1..100000000] of int64;max,i,d,n:longint;

begin
assign(input,'bai3.inp');reset(input);
assign(output,'bai3.out');rewrite(output);
d:=0;max:=0;
readln(n);
for i:=1 to n do
    begin
    read(a[i]);
    if a[i]>0 then
        begin
            d:=d+1;
            if max<d then max:=d;
        end
        else d:=0;
    end;
writeln(max);
end.
