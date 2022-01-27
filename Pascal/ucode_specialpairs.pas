var i,j:longint;
///////////////////////////////////////
begin
for x := a to b+1 do
    for y in range (a,b+1):
    if (a<= x**2<=b) and (a<= y**3<=b) and abs((x**2)-(y**3)) <= k then
    d = d+1
writeln(d);
end.