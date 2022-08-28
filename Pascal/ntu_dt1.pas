var i,n,l:longint;
    a:qword;
///////////////////////////////////////
begin
readln(n);
l := 1;
a := 0;
while (true) do
    begin
    for i := 1 to l do
        begin
        a := a + l;
        n := n - 1;
        if (n = 0) then
            begin
            writeln(a);
            halt;
            end;
        end;
    while (a mod (l + 1) > 0) do
        a := a - 1;
    l := l + 1;
    end;
end.