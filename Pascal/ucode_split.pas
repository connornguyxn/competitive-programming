var a:array[0..100000000] of longint;
    i,n,mn,p:longint;

function s(l,r:longint):longint;
begin
    exit(a[r]-a[l-1]);
end;

function abs(a:longint):longint;
begin
if a<0 then
    exit(a*-1);
exit(a);
end;

begin
readln(n);
for i:=1 to n do
    begin
    read(a[i]);
    a[i]:=a[i]+a[i-1];
    end;
mn:=abs(a[n]);
for i:=1 to n do
    if (abs(s(1,i)-s(i+1,n))<mn) then
        begin
        mn:=abs(s(1,i)-s(i+1,n));
        end;
writeln(mn);
end.