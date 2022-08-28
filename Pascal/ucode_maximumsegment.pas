var a:array[0..100000000] of int64;
    i,n,k,mx:longint;
////////////////////////////////////
begin
readln(n,k);
for i:=1 to n do
    begin
    read(a[i]);
    a[i]:=a[i]+a[i-1];
    end;
mx:=low(mx);
for i:=1 to n-k+1 do
    begin
    if a[i+k-1]-a[i-1]>mx then
        begin
        mx:=a[i+k-1]-a[i-1];
        end;
    end;
writeln(mx);
end.