var a:array[0..1000000] of int64;
t:int64;
i,j,k,n,u,v,min:longint;
///////////////////////////////////
function timnp(l,r:longint):longint;
var t1,t2,t,g,u,v:longint;
begin
timnp:=maxlongint;
while l<=r do
    begin
    g:=(l+r) div 2;
    t1:=a[g]-a[u-1];
    t2:=a[v]-a[g];
    t:=abs(t1-t2);
    if t<timnp then timnp:=t;
    if t1<t2 then
        l:=g+1
    else
        r:=g-1;
    end;
end;
//////////////////////////////////
begin
assign(input,'chenhlech.inp');reset(input);
assign(output,'chenhlech.out');rewrite(output);
a[0]:=0;
readln(n);
for i:=1 to n do
    begin
    read(a[i]);
    a[i]:=a[i]+a[i+1];
    end;
for k:=1 to n do
    begin
    readln(u,v);
    for i:=u to v-1 do
        begin
        min:=maxlongint;
        for j:=i+1 to u do
            t:=abs(a[v]-2*a[i]+a[u-1]);
        if t<min then min:=t;
        end;
    end;
writeln(timnp(u,v))
end.