var t,l,r,n,k:int64;
i,q:longint;

begin
//assign(input,'ucode_sumseq.inp');reset(input);
//assign(output,'ucode_sumseq.out');rewrite(output);
readln(n,q);
t:=0;
for i:=1 to q do
    begin
    readln(l,r,k);
    t:=t+(r-l+1)*k;
    end;
writeln(t);
end.
