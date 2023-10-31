var a:array[1..100000000] of int64;i,k,n:longint;
//////////////////////////////////////////////////////
begin
assign(input,'bai4.inp');reset(input);
assign(output,'bai4.out');rewrite(output);
readln(n);
for i:=1 to n do read(a[i]);



for i:=1 to n do write(a[i],' ');
end.