var a,b,tg:int64;
i,n,d:longint;
////////////////////////////////////////////////
function dx(a:int64):longint;
var i:longint;x:ansistring;
begin
str(a,x);
dx:=1;
for i:=1 to length(x) div 2 do
    if x[i]<>x[length(x)-i+1] then exit(0);
end;
////////////////////////////////////////////////
begin
assign(input,'cntpalin.inp');reset(input);
assign(output,'cntpalin.out');rewrite(output);
readln(n);
for i:=1 to n do
    begin
    readln(a,b);
    d:=0;
    if a>b then
        begin
        tg:=a;
        a:=b;
        b:=tg;
        end;
    while a<b do
        begin
        d:=d+dx(a);
        a:=a+1;
        end;
    writeln(d);
    end;
end.