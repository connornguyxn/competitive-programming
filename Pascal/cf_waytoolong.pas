var a,kq:ansistring;
n,i:longint;

begin
readln(n);
for i:=1 to n do
    begin
    readln(a);
    if length(a)<=10 then
        writeln(a)
    else
        begin
        write(a[1],length(copy(a,2,length(a)-2)),a[length(a)]);
        writeln;
        end;
    end;
end.