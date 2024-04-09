var a:array[1..100000000] of longint;
    i,n:longint;
/////////////////////////////////////
procedure try(k:longint);
var i:longint;
    begin
    if k=n+1 then
        begin
        for i:=1 to n do
            begin
            write(a[i]);
            end;
        writeln();
        end
    else
        begin
        for i:=0 to 1 do
            begin
            a[k]:=i;
            try(k+1);
            end;
        end;
    end;
/////////////////////////////////////
begin
readln(n);
try(1);
end.