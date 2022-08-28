var a:ansistring;
///////////////////////////////////////////////////
function dectobin(a:ansistring):ansistring;
var b:ansistring;
e:longint;
x:int64;
begin
val(a,x,e);
while x<>0 do
    begin
    str(x mod 2,b);
    dectobin:=b+dectobin;
    x:=x div 2;
    end;
end;
///////////////////////////
function bintodec(a:ansistring):ansistring;
var i,j,b,kt:longint;
t,kq:int64;
begin
for i:=length(a) downto 1 do
    begin
    t:=1;
    for j:=1 to length(a)-i do
        t:=t*2;
    val(a[i],b,kt);
    kq:=kq+(b*t);
    end;
str(kq,bintodec);
end;
///////////////////////////
function rev(a:ansistring):ansistring;
var i:longint;
begin
rev:='';
for i:=1 to length(a) do
    rev:=a[i]+rev;
end;
//////////////////////////////////////////////
begin
readln(a);
a:=rev(dectobin(a));
while a[1]='0' do
    delete(a,1,1);
writeln(bintodec(a));
end.
