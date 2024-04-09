var a:ansistring;
//////////////////////////////////
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
//////////////////////////////////
begin
assign(input,'nhiphannguoc.inp');reset(input);
assign(output,'nhiphannguoc.out');rewrite(output);
readln(a);
writeln(bintodec(a));
end.