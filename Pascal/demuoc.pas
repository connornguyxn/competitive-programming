//coded w/ <3 by inf1nity
var a:array[1..100000000] of longint;
    i,j,n,d,dmx,mx:longint;
//////////////////////////////////////
begin
readln(n);
for i:=1 to n do
    read(a[i]);
dmx:=0;
for i:=1 to n do
    begin
    d:=0;
    for j:=1 to n do
        if a[i] mod a[j]=0 then
            d:=d+1;
    if d>dmx then
        begin
        mx:=a[i];
        dmx:=d;
        end;
    end;
writeln(mx);
end.