var a:array[1..1000000] of longint;
n,i,m:longint;
////////////////////////////////////
function binsearch(mg:array of longint;n,a:longint):longint;
var dau,cuoi,giua:longint;
begin
dau:=1;
cuoi:=n;
while dau<=cuoi do
    begin
    giua:=(dau+cuoi) div 2;
    if a=mg[giua] then
        exit(giua)
    else
        if a<mg[giua] then
            cuoi:=giua-1
        else
            dau:=giua+1;
    end;
exit(-1);
end;
////////////////////////////////////
begin
assign(input,'binsearch.inp');reset(input);
assign(output,'binsearch.out');rewrite(output);
readln(n,m);
for i:=1 to n do read(a[i]);
writeln(binsearch(a,n,m));
end.
