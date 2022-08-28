var a:array[1..100000000] of longint;
    n,i,j,mx,l,r:longint;
//////////////////////////////////////////
function ispalin(l,r:longint):boolean;
var i:longint;
begin
for i:=l to r div 2 do
    if a[i]<>a[r-i+1] then
        exit(false);
exit(true);
end;
//////////////////////////////////////////
begin
read(n);
for i:=1 to n do
    read(a[i]);
for i:=1 to n-1 do
    for j:=i+1 to n do
        if ispalin(i,j) and (j-i+1>mx) then
            begin
            mx:=j-i+1;
            l:=i;
            r:=j;
            end;
for i:=l to r do
    write(a[i],' ');
end.