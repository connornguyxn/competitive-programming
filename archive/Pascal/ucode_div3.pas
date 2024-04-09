var d:array[0..2] of longint;
    a,i,n:longint;

begin
//assign(input,'ucode_div3.inp');reset(input);
//assign(output,'ucode_div3.out');rewrite(output);
readln(n);
for i:=1 to n do
    begin
    read(a);
    a:=a mod 3;
    d[a]:=d[a]+1;
    end;
d[0]:=d[0]*(d[0]-1) div 2;
writeln(d[0]+d[1]*d[2]);
end.