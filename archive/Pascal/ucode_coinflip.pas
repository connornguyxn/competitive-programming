var a:array[1..100000000] of longint;
n,i,j,l,r,d:longint;

begin
readln(n);
d:=0;
for i:=1 to n do
    begin
    read(a[i]);
    if a[i]=1 then
        begin
        a[i]:=a[i-1]-1;
        d:=d+1;
        end
    else
        a[i]:=a[i-1]+1;
    end;
for i:=1 to n-1 do
    for j:=i to n do
        if a[j]-a[i-1]>a[r]-a[l-1] then
            begin
            l:=i;
            r:=j;
            end;
for i:=l to r do
    if a[i]<a[i-1] then
        d:=d-1
    else
        d:=d+1;
writeln(d);
end.