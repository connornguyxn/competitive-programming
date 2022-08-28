var n,k:int64;

begin
assign(input,'timsok.inp');reset(input);
assign(output,'timsok.out');rewrite(output);
read(n,k);
if k<=(n+1 div 2) then writeln((k-1)*2+1)
    else writeln((k-1)*2+2);
end.
