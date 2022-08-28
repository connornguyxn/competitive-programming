var n,k,a1,a2:int64;
astr:ansistring;
i:longint;
////////////////////////////////////////////////////
function mu(a,b:int64):int64;
var i:longint;
begin
mu:=1;
for i:=1 to b do
    mu:=mu*a
end;
///////////////////////////////////////////////////
begin
assign(input,'timkssh.inp');reset(input);
assign(output,'timkssh.out');rewrite(output);
readln(k);
/////
if k<10 then
    begin
    writeln(k);
    exit();
    end;
for i:=2 to 18 do
    begin
    a1:=a2+9+mu(10,i-1)*i;
    if k<a1 then
        begin
        n:=i;
        break;
        end;
    end;
k:=k-a2;
/////
writeln(k);
{if k mod n=0 then
    str((mu(10,n-1)+k div n),astr)
else
    str((mu(10,n-1)+k div n-1),astr);
writeln(astr);
if (k mod length(astr)=0) then
    writeln(astr[length(astr)])
else
    writeln(astr[k mod length(astr)]);}
end.
