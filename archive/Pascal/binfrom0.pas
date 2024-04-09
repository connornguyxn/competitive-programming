uses crt;
var n,i:longint;
////////////////////////
function bin(a:longint):ansistring;
var i:longint;
b:ansistring;
begin
b:='';
while a<>0 do
    begin
    str(a mod 2,b);
    bin:=b+bin;
    a:=a div 2;
    end;
end;
////////////////////////
begin;
clrscr;
readln(n);
for i:=0 to n do
    writeln(bin(i));
readln;
end.