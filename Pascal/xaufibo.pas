var k,i,d:longint;
    f1,f2,fn,a:string;
///////////////////////////////
function count(a,b:string):longint;
begin
count:=0;
while pos(b,a)<>0 do
    begin
    count:=count+1;
    delete(a,pos(b,a),1);
    end;
end;
//////////////////////////////////
begin
readln(k);
readln(a);
d:=d+count(a,'A');
f1:='A';
f2:='B';
for i:=1 to k-1 do
    begin
    fn:=f1+f2;
    d:=d+count(a,fn);
    writeln(fn);
    f1:=f2;
    f2:=fn;
    end;
writeln(d);
end.