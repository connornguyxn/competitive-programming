var a:ansistring;
///////////////////////

function tcs(a:ansistring):ansistring;
var i,b,kt:longint;
t:int64;
begin
t:=0;
for i:=1 to length(a) do
    begin
    val(a[i],b,kt);
    t:=t+b;
    end;
str(t,tcs);
end;

///////////////////////////
begin
assign(input,'timso2016.inp');reset(input);
assign(output,'timso2016.out');rewrite(output);
readln(a);
while length(a)<>1 do
    a:=tcs(a);
writeln(a);
end.