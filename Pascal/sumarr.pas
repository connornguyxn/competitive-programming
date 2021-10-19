var a:array[0..100000000] of int64;
x,y,i,n,q:longint;
//////////////////////////////////
begin
readln(n);
for i:=1 to n do
    begin
    read(a[i]);
    a[i]:=a[i]+a[i-1];
    end;
readln(q);
for i:=1 to q do
    begin
    readln(x,y);
    writeln(a[y]-a[x-1]);
    end;
end.