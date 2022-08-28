var a,t:array[0..100000000] of longint;
i,j,n,d,k,max,s:longint;
//:int64;

begin
assign(input,'sodanggi.inp');reset(input);
assign(output,'sodanggi.out');rewrite(output);
readln(n,k);
max:=0;d:=0;
for i:=1 to n do
    begin
    read(a[i]);
    t[i]:=a[i]+a[i-1];
    end;
for i:=1 to n-1 do
    begin
    for j:=i+1 to n do
        begin
        s:=a[j]-a[i-1];
        if s=k then
            begin
            d:=j-i+1;
            if max<d then max:=d;
            end;
        end;
    end;
//for i:=1 to n do write(t[i],' ');
writeln(max);
end.
