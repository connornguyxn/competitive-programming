var a:array[1..1000000] of int64;
i,n,x:longint;
///////////////////////////////////////////////////////////
procedure bubblesort(var a:array of int64; n:longint);
var i,j:longint;
begin
for i:=2 to n do
    for j:=n downto i do
        if a[j]>a[j-1] then
            begin
            a[j]:=a[j]+a[j-1];
            a[j-1]:=a[j]-a[j-1];
            a[j]:=a[j]-a[j-1];
            end;
end;
///////////////////////////////////////////////////////////
begin
assign(input,'test.inp');reset(input);
assign(output,'test.out');rewrite(output);
readln(n);
for i:=1 to n do
    read(a[i]);
bubblesort(a,n);
for i:=1 to n do
    write(a[i],' ');
end.
