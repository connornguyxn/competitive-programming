var n,j,i,k:longint;
a:array[1..100000000] of longint;
br:boolean;
t:int64=0;

begin
assign(input,'loop.inp');reset(input);
assign(output,'loop.out');rewrite(output);
readln(n,k);
for i:=1 to n do
    read(a[i]);
i:=1;
while (a[i] mod k)=0 do
    begin
    for j:=1 to k do
        a[n+j]:=a[i] div k;
    n:=n+j;
    if br=true then break;
    if (a[i] div k) mod k<>0 then
        br:=true;
    i:=i+1;
    end;
for i:=1 to n do
    begin
    t:=t+a[i];
    write(a[i],' ');
    end;
writeln();
writeln(t);
end.
