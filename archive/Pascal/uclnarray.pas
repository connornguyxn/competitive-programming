var a:array[1..10000000] of int64;i,n,j:longint;d:int64;
///////////////////////////////
function ucln(a,b:int64):int64;
var r:int64;
begin
while b<>0 do
    begin
    r:=a mod b;
    a:=b;
    b:=r;
    end;
ucln:=a
end;
///////////////////////////////
begin
assign(input,'bai1.inp');reset(input);
assign(output,'bai1.out');rewrite(output);
readln(n);
read(a[1],a[2]);
d:=ucln(a[1],a[2]);
for i:=3 to n do
    begin
    read(a[i]);
    d:=ucln(d,a[i]);
    end;
for i:=1 to n-1 do
    for j:=i+1 to n do if ucln(a[i],a[j])=1 then write(a[i],' ',a[j]);
writeln(d);
end.
