function mu(a,n:int64):int64;
var i:longint;
    begin
    mu := 1;
    for i:=1 to n do
        mu := mu * a;
    end;