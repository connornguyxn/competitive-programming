var a,bk,b,mn:ansistring;
n,i,d,m,m2:longint;

begin
n:=1;
while true do
    begin
    readln(b);
    if b='***' then
        break;
    a:=a+b+'.';
    n:=n+1;
    end;
bk:=a;
while pos('.',a)<>0 do
    begin
    b:=copy(a,1,pos('.',a));
    d:=0;
    while pos(b,a)<>0 do
        begin
        d:=d+1;
        delete(a,pos(b,a),length(b));
        end;
    if d>m then
        begin
        m:=d;
        mn:=b;
        end;
    end;
a:=bk;
while pos(mn,a)<>0 do
    delete(a,pos(mn,a),length(mn));
//writeln(a);
while pos('.',a)<>0 do
    begin
    b:=copy(a,1,pos('.',a));
    d:=0;
    while pos(b,a)<>0 do
        begin
        d:=d+1;
        delete(a,pos(b,a),length(b));
        end;
    if d>m2 then
        m2:=d;
    end;
delete(mn,length(mn),1);
if m=m2 then
    writeln('Runoff!')
else
    writeln(mn);
end.
