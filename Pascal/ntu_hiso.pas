var a:array[1..100000000] of longint;
    i,j,n,mx:longint;
//////////////////////////////////////
begin
//assign(input,'ntu_hiso.inp');reset(input);
readln(n);
for i:=1 to n do
    read(a[i]);
for i:=1 to n-1 do
    for j:=i+1 to n do
        if a[j]-a[i]>mx then
            mx:=a[j]-a[i];
writeln(mx);
end.