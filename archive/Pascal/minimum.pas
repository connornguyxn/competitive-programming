uses crt;
var a,b,istr:ansistring;i,j:longint;

begin
clrscr;
readln(a);
for i:=1 to 9 do
    for j:=1 to length(a) do
        begin
        str(i,istr);
        if a[j]=istr then
            begin
            b:=b+istr;
            end;
        end;
writeln(b);
readln;
end.