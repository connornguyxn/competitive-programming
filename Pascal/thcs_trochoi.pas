var a:array[0..100000000] of qword;
    i,n,s,t,l,r:longint;
{=====================================}
begin
assign(input,'thcs_trochoi.inp');reset(input);
//assign(output,'thcs_trochoi.out');rewrite(output);
readln(n,l,d);
for i:=1 to n do
    begin
    read(a[i]);
    a[i]:=a[i]+a[i-1];
    end;
if (l+d <= n) then
    begin
    writeln(a[l+s-1]-a[l-1]);
    halt;
    end;
t:=t+a[n];
d:=d-(n-t+1);

end.
//1 2 3 4 5 6