var x,y,t2:ansistring;i,j,kt:longint;a,t1:int64;
//////////////////
function slp(x:ansistring):int64;
begin
while length(x)<>1 do
    begin
    t1:=0;
    for i:=1 to length(x) do
        begin
        val(x[i],a,kt);
        t1:=t1+a;
        end;
    slp:=t1;
    str(t1,t2);
    x:=t2;
    end;
end;
/////////////////////////////////////
begin
assign(input,'solocphat.inp');reset(input);
assign(output,'solocphat.out');rewrite(output);
readln(x);
readln(y);
writeln(slp(x));
if (slp(x)=6) or (slp(x)=8) then writeln('YES')
    else writeln('NO');
if (slp(y)=6) or (slp(y)=8) then writeln('YES')
    else writeln('NO');
end.