var n,i:longint;
    a:array[0..100000000] of longint;
///////////////////////////////////////
procedure try(t,n:longint);
    var i:longint;
    /////////////////
    begin
    write(t,' ');x
    if (n <> 0) then
        begin
        for i := 1 to 2 do
            try(t + a[i],n - 1);
        end;
    end;
///////////////////////////////////////
begin
readln(n);
a[1] := 3;
a[2] := 2;
try(0,n)
end.