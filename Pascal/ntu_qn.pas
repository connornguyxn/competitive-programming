var a:ansistring;
    c,n,i:longint;
/////////////////////////////////
function stri(n:longint):ansistring;
    begin
    str(n,stri);
    end;
/////////////////////////////////
begin
readln(n);
a:=' ';
for i:=1 to n do
    begin
    read(c);
    a:=a+stri(c)+' ';
    end;
i:=0;
while pos(' '+stri(sqr(i))+' ',a)<>0 do
    i:=i+1;
writeln(sqr(i));
end.