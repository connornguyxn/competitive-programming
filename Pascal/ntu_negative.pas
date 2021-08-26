var a:int64;
i:longint;
b:ansistring;
//////////////////////////////////////////
function bintodec(a:ansistring):int64;
var i,j,b,kt:longint;
t:int64;
begin
bintodec:=0;
for i:=length(a) downto 1 do
    begin
    t:=1;
    for j:=1 to length(a)-i do
        t:=t*2;
    val(a[i],b,kt);
    bintodec:=bintodec+(b*t);
    end;
end;
/////
function dectobin(a:int64):ansistring;
var b:ansistring;
begin
while a<>0 do
    begin
    str((a mod 2),b);
    dectobin:=b+dectobin;
    a:=a div 2;
    end;
end;

//////////////////////////////////////////
begin
//assign(input,'ntu_negative.inp');reset(input);
//assign(output,'ntu_negative.out');rewrite(output);
readln(a);
b:=dectobin(a);
for i:=1 to length(b) do
    begin
    if b[i]='1'then
        b[i]:='0'
    else
        b[i]:='1';
    end;
while b[1]='0' do
    delete(b,1,1);
writeln(bintodec(b));
end.
