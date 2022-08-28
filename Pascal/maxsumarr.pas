//coded w/ <3 by inf1nity
var a:array[0..100000000] of int64;
    i,j,n,mx,k:longint;
//////////////////////////////////
begin
readln(n);
for i:=1 to n do
    begin
    read(a[i]);
    a[i]:=a[i]+a[i-1];
    end;
readln(k);
for i:=1 to n-1 do
    for j:=i+1 to n do
        if (a[j]-a[i-1]>mx) and (a[j]-a[i-1]<=k) then
            mx:=a[j]-a[i-1];
writeln(mx);
end.