var a,c,b:ansistring;
k,t,d,out:longint;
/////////////////////////////////////
function cnum(a,c:ansistring):longint;
begin
cnum:=0;
while pos(c,a)<>0 do
    begin
    cnum:=cnum+1;
    delete(a,pos(c,a),1);
    end;
end;
///////////////////////////////////
begin
assign(input,'ktt.inp');reset(input);
assign(output,'ktt.out');rewrite(output);
readln(a);
readln(k);
readln(c);
d:=cnum(a,c);
if d=0 then
    begin
    writeln(0);
    halt;
    end;
t:=((k+1)*k div 2) mod length(a);
out:=out+cnum(copy(a,t+1,length(a)),c);
out:=out+((k+t-length(a)) div length(a))*d;
if k mod length(a)<>0 then
    out:=out+cnum(copy(a,1,k mod length(a)),c);
writeln(out);
end.
