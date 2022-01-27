var a:array[0..100000000] of longint;
    i,n,c:longint;
///////////////////////////////////////
begin
readln(n);
for i := 1 to n do
    begin
    read(c);
    a[c] := i;
    end;
for i := 1 to n do
    write(a[i],' ');    
end.