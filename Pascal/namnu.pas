var m,n,nam,nu,i:longint;a:ansistring;
begin
assign(input,'namnu.inp');reset(input);
assign(output,'namnu.out');rewrite(output);
readln(m,n);
readln(a);
//a:=a+a[1];
for i:=1 to length(a)-1 do
    if a[i]=a[i+1] then
        if a[i]='1' then inc(nam) else inc(nu);
if a[1]=a[length(a)] then
    if a[1]='1' then inc(nam)
    else inc(nu);
write(abs(nam-nu));
end.
