var n,m,i:longint; max,max1,min,min1,a,mxp:int64;
begin
readln(n,m);
max:=-maxlongint;
max1:=-maxlongint;
min:=maxlongint;
min1:=maxlongint;
for i:=1 to n do
    begin
    read(a);
    if a>max then max:=a;
    if a<min then min:=a;
    end;
for i:=1 to m do 
    begin
    read(a);
    if a>max1 then max1:=a;
    if a<min1 then min1:=a;
    end;
mxp := -maxlongint;
if (min * max1 > mxp) then
    mxp := min * max1;
if (min * min1 > mxp) then
    mxp := min * min1;
if (max * max1 > mxp) then
    mxp := max * max1;
if (max * min1 > mxp) then
    mxp := max * min1;
writeln(mxp);
end.