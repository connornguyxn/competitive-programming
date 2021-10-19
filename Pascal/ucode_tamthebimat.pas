var n,i,k:longint;
t:qword;

begin
readln(n);
t:=(n+1) * n div 2;
for i:=1 to n-1 do
    begin
    readln(k);
    t:=t-k;
    end;
writeln(t);
end.