var a,i,n,d,j:longint;
    kq:array[0..1000000] of longint;
///////////////////////////////////////
begin
assign(input,'test.inp');reset(input);
readln(n);
for i := 1 to n do
    begin
    read(a);
    if (a in [6,28,496,8128]) then
        begin
        d := d + 1;
        kq[d] := a;
        end;
    end;
writeln(d);
for i := 1 to d do
    write(kq[i],' ');
end.