var l,r:int64;
    i,d:longint;
//////////////////////
begin
readln(l,r);
i:=trunc(sqrt(l))+1;
d:=0;
while sqr(i)<r do
    begin
    d:=d+1;
    i:=i+1;
    end;
writeln(d);
end.