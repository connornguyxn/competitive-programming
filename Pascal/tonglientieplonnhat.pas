var a:array[0..100000000] of int64;
    i,l,r,n,mx,mxc:longint;

begin
readln(n);
for i:=1 to n do
    begin
    read(a[i]);
    a[i]:=a[i]+a[i-1];
    end;
for l:=1 to n-1 do
    for r:=l+1 to n do
        begin
        if a[r]-a[l-1]>=mx then
            begin
            mx:=a[r]-a[l-1];
            mxc:=r-l+1;
            end;
        end;
writeln(mxc)
end.