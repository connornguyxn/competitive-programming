var a:array[0..1000000] of longint;
    i,n,l,lmn,rmn:longint;
    s,rs:int64;
///////////////////////////////////////
begin
assign(input,'test.inp');reset(input);
readln(n,rs);
lmn := 1;
rmn := n + 1;
l := 1;
for i := 1 to n do
    begin
    read(a[i]);
    s := s + a[i];
    if (s >= rs) then
        begin
        while (s >= rs) do
            begin
            if (i - l + 1 <= rmn - lmn + 1) then
                begin
                //writeln(i,' ',l);
                rmn := i;
                lmn := l;
                end;
            s := s - a[l];
            l := l + 1;
            end;
        end;
    end;
if (rmn = n + 1) then
    writeln(-1)
else
    begin
    writeln(rmn - lmn + 1);
    for i := lmn to rmn do
        write(a[i],' ');
    end;
end.