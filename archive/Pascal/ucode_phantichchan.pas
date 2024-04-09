var n,test,tests:longint;
t:qword;

begin
readln(tests);
for test:=1 to tests do
    begin
    readln(n);
    if ((n div 2) mod 2=0) then
    
    n:=(n-1) div 2;
    t:=(n+1) * n div 2 + 1;
    writeln(t);
    end;
end.