var a,b:array[1..10000000] of int64;n,k,d,max,maxd:int64;i,j:longint;

begin
assign(input,'mod.inp');reset(input);
assign(output,'mod.out');rewrite(output);
readln(n,k);
max:=0;
for i:=1 to n do
    begin
    read(a[i]);
    b[i]:=a[i] mod k;
    end;
for i:=0 to k-1 do
    begin
    d:=0;
    for j:=1 to n do
        begin
        if i=b[j] then
            begin
            d:=d+1;
            if max<d then
                begin
                maxd:=i;
                max:=d;
                end;
            end;
        end;
    end;
writeln(maxd,' ',max);
end.
