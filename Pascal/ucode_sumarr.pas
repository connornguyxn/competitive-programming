var a:array[0..100000000] of longint;
x,y,i,j,n,q:longint;
t:int64;

begin
readln(n);
for i:=1 to n do
    begin
    read(a[i]);
    a[i]:=a[i]+a[i-1];
    end;
readln(q);
for j:=1 to q do
    begin
    readln(x,y);
    writeln(a[y]-a[x-1]);
    end;
end.