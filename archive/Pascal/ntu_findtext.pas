var a,b,inp:ansistring;
i,d,p,max:longint;

begin
assign(input,'findtext.inp');reset(input);
assign(output,'findtext.out');rewrite(output);
readln(inp);
i:=1;
max:=0;
p:=0;
while length(b)<>(length(a) div 2)+1 do
    begin
    a:=inp;
    b:=copy(a,1,i);
    delete(a,1,i);
    if pos(b,a)<>0 then
        begin
        max:=i;
        p:=pos(b,a);
        end;
    i:=i+1;
    end;
writeln(max,' ',p+1);
end.
