//coded w/ <3 by inf1nity
var mg:array[1..100000000] of longint;
    i,n,d,a:longint;
/////////////////////////////////////
begin
readln(n);
d:=0;
for i:=1 to n do
    begin
    read(a);
    mg[a]:=mg[a]+1;
    if mg[a] mod 2=0 then
        d:=d+1;
    end;
writeln(d);
end.