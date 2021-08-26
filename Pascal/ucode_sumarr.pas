var a:array[1..100000000] of longint;
x,y,i,j,n,q:longint;
t:int64;

begin
assign(input,'ucode_sumarr.inp');reset(input);
assign(output,'ucode_sumarr.out');rewrite(output);
readln(n);
for i:=1 to n do
    read(a[i]);
readln(q);
for j:=1 to q do
    begin
    readln(x,y);
    t:=0;
    for i:=x to y do
        t:=t+a[i];
    writeln(t);
    end;
end.