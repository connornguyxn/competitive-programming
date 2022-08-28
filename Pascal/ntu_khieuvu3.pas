//////////////////////////////
type mg=array [1..1000000] of int64;
var i,j,n:longint; x,tg:int64;
    a:mg;
{=====================================}
procedure qsort(var a:mg;l,r: longint);
begin
i:=l;
j:=r;
x:=a[(l+r) div 2];
repeat
 while a[i]<x do inc(i);
 while x<a[j] do dec(j);
 if j>=i then
  begin
   tg:=a[i];
   a[i]:=a[j];
   a[j]:=tg;
   inc(i);
   dec(j);
  end;
until i>j;
if l<j then qsort(a,l,j);
if i<r then qsort(a,i,r);
end;
//////////////////////////////
//////////////////////////////
function tknp(x,d,c:longint):longint;
var g:longint;
begin
    while d<=c do
        begin
            g:=(d+c) div 2;
            if x=a[g] then exit(g);
            if x<a[g] then c:=g-1
                else d:=g+1;
        end;
    tknp:=0;
end;
/////////////////////////////
var k,d,thu,kq,t:int64;
begin
//assign(input,'Khieuvu3ntu.inp'); reset(input);
//assign(output,'Khieuvu3ntu.out'); rewrite(output);
read(n,k); d:=0; kq:=0;
for i:=1 to n do read(a[i]);
qsort(a,1,n);
for i:=1 to n-1 do
    begin
    thu:=a[i]+k;
    if tknp(thu,i+1,n)>0 then kq:=kq+1 else d:=d+1;
    end;
if d=n-1 then writeln(0) else writeln(kq);
end.