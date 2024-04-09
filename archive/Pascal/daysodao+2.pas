uses crt;
var a,k,i:int64;
j:longint;
/////////////////////////
function dao(a:int64):int64;
var i,kt:longint;
x,y:ansistring;
begin
str(a,x);
y:='';
for i:=1 to length(x) do
    y:=x[i]+y;
val(y,dao,kt);
end;
/////////////////////////
begin
clrscr;
//readln(k);
i:=1;a:=1;
for j:=1 to 20 do
begin
a:=1;
while i<=j do
    begin
    i:=i+1;
    a:=dao(a)+2;
    end;
writeln(a)
end;
readln
end.