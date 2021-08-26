var i,j,n,mm:longint;
a:array[1..100000000] of longint;
//////////////////////////////////
begin
assign(input,'ntu_queue.inp');reset(input);
assign(output,'ntu_queue.out');rewrite(output);
readln(n);
for i:=1 to n do
    read(a[i]);
for i:=1 to n-1 do
    for j:=i+1 to n do
        if a[i]>a[j] then
            begin
            writeln(a[i],' ',a[j]);
            mm:=a[i];
            a[i]:=a[j];
            a[j]:=mm;
            end;
for i:=1 to n do
    write(a[i],' ');
end.
