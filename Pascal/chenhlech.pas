var a:array [0..1000000] of int64;u,v,n,m:int64;i:longint;
////////////////////////////////////////
function chatnp(l,r:longint):longint;
var t1,t2,t:int64;g:longint;
begin
chatnp:=maxlongint;
    while l<=r do
        begin
            g:=(l+r) div 2;
            t1:=a[g]-a[u-1];
            t2:=a[v]-a[g];
            t:=abs(t1-t2);
            if t<chatnp then chatnp:=t;
            if t1<t2 then l:=g+1
                else r:=g-1;
        end;
end;
/////////////////////////////////////////
begin
//assign(input,'chenhlech.inp');reset(input);
//assign(output,'chenhlech.out');rewrite(output);
readln(n,m);
for i:=1 to n do
    begin
        read(a[i]);
        a[i]:=a[i-1]+a[i];
    end;
for i:=1 to m do
    begin
        readln(u,v);
        writeln(chatnp(u,v));
    end;
end.
