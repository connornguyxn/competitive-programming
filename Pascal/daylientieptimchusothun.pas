function stri(a:longint):ansistring;
    begin
    str(a,stri);
    end;

function int(a:ansistring):longint;
var kt:longint;
    begin
    val(a,int,kt);
    end;
/////////////////////////////////////
var n,t,i,l,a,p:longint;
scs:ansistring;
begin
readln(n);
if n<10 then
    begin
    writeln(n);
    halt();
    end;
scs:='10';
n:=n;
t:=9;
while t<=n do
    begin
    l:=(int(scs+'0')-int(scs))*length(scs);
    t:=t+l;
    scs:=scs+'0';
    end;
t:=t-l;
n:=n-t;
scs:=stri(int(scs) div 10);
n:=n div length(scs);
p:=n mod length(scs);
if p<>0 then
    n:=n+1;
writeln(t);
writeln(stri(int(scs)+n));
end.