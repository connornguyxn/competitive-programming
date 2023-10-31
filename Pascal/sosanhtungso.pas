uses crt;
type mg=array[1..3] of int64;
var a:mg;

procedure sx(var a:mg);
var i,j:longint;tg:int64;
begin
for i:=1 to 2 do
    for j:=i+1 to 3 do
       if a[i]>a[j] then
           begin
           tg:=a[i];
           a[i]:=a[j];
           a[j]:=tg;
           end;
end;

function dao(inp:int64):int64;
var i:longint;
a:;
begin
str()

end;

begin
clrscr;
readln(a[1],a[2],a[3]);
sx(a);
writeln(a[1],' ',a[2],' ',a[3]);

end.