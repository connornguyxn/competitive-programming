var lib:array[0..9] of longint=(1,0,0,0,1,0,1,0,2,1);
a:ansistring;
i,b,kt:longint;
t:int64;


begin
assign(input,'lohong.inp');reset(input);
assign(output,'lohong.out');rewrite(output);
readln(a);
for i:=1 to length(a) do
    begin
    val(a[i],b,kt);
    t:=t+lib[b];
    end;
writeln(t);
end.
