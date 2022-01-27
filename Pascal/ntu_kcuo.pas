var d,n,i,j:longint;

begin
readln(n);
d := 1;
for i := 1 to (n div 2 + 1) do
    begin
    for j := 1 to ((n - d) div 2) do
        write('*');
    for j := 1 to d do 
        write('D');
    for j := 1 to ((n - d) div 2) do
        write('*');
    writeln();
    d := d + 2;
    end;
d := d - 4;
for i := 1 to (n div 2) do
    begin
    for j := 1 to ((n - d) div 2) do
        write('*');
    for j := 1 to d do 
        write('D');
    for j := 1 to ((n - d) div 2) do
        write('*');
    writeln();
    d := d - 2;
    end;
end.