var res:array[0..1] of string = ('YES','NO');
    a,i,n:longint;
///////////////////////////////////////
begin
readln(n);
for i := 1 to n do
    begin
    readln(a);
    writeln(res[a mod 2]);
    end;
end.