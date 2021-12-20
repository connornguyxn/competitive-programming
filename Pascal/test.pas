var a:array[1..100000000] of longint;
    i,n,l,r,t:longint;

begin
readln(n);
for i:=1 to n do
    begin
    read(a[i]);
    a[i]:=a[i]+a[i-1];
    end;
for i:=1 to n do
    begin
    write(a[i],' ');
    end;
readln(l,r);
t:=a[r]-a[l-1];
writeln(t);
end.