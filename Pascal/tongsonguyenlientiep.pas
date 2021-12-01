var a:array[0..100000000] of int64;
    i,l,r,n,k,f,loops:longint;

begin
assign(input,'tongsonguyenlientiep.inp');reset(input);
assign(output,'tongsonguyenlientiep.out');rewrite(output);
readln(n);
for i:=1 to n do
    begin
    read(a[i]);
    a[i]:=a[i]+a[i-1];
    end;
k:=n+1;
for l:=1 to n-1 do
    for r:=l+1 to n do
        begin
        if r-l+1<k then
            begin
            if (a[r]-a[l-1]) mod n=0 then
                begin
                k:=r-l+1;
                f:=l;
                end;
            end
        else
            break;
        end;
writeln(k);
writeln(f);
end.