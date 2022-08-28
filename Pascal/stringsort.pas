type ar=array[1..1000000] of string;
var a:ar;
    n,i,tmp:longint;
//////////////////////////////////////////////
procedure sort(var a:ar;l,r:string);
var i,j,m:longint;
    tmp:string;
begin
i:=l;
j:=r;
m:=a[(l+r) div 2];
while i<=j do
    begin
    while a[i]<m do
        i:=i+1;
    while a[j]>m do
        j:=j-1;
    if i<=j then
        begin
        tmp:=a[i];
        a[i]:=a[j];
        a[j]:=tmp;
        i:=i+1;
        j:=j-1;
        end;
    end;
if i<r then
    sort(a,i,r);
if j>l then
    sort(a,l,j);
end;
//////////
function stri(a:longint):string;
begin
str(a,stri);
end;
//////////
function int(a:string):longint;
var tmp:longint;
begin
val(a,int,tmp);
end;
////////////////////////////
begin
readln(n);
for i:=1 to n do
    begin
    readln(tmp);
    a[i]:=stri(tmp);
    end;

end.