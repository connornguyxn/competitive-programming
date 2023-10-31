var a,b:array [0..1000000] of longint;
i,n,t,m,p:longint;
////////////////////////////////////////////////////////////////
function search(x,l,r:longint):longint;
var pos,mid:longint;
begin
while l<=r do
    begin
    mid:=(l+r) div 2;
    if x<=b[mid] then
        begin
        pos:=mid;
        r:=mid-1;
        end
    else l:=mid+1;
    end;
exit(pos);
end;
////////////////////////////////////////////////////////////////
begin
//assign(input,'nauan.inp');reset(input);
//assign(output,'nauan.out');rewrite(output);
readln(n);
b[0]:=0;
for i:=1 to n do
    begin
        read(a[i]);
        b[i]:=b[i-1]+a[i];
    end;
readln(m);
for i:=1 to m do
    begin
        read(p);
        write(search(p,1,n),' ');
    end;
end.
