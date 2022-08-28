var a:array[1..1000000] of longint;
    i,n,mn,mx:longint;
///////////////////////////////////////
begin
assign(input,'ntu_hiso.inp');reset(input);
readln(n);
mn := 1;
mx := 0;
read(a[1]);
for i := 2 to n do
    read(a[i]);
end.