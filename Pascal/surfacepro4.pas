//rewritten for the 5th time
var a,b,tt,ht,kq:ansistring;
i:longint;

begin
assign(input,'surfacepro4.inp');reset(input);
assign(output,'surfacepro4.out');rewrite(output);
readln(a);
kq:='Just a joke';
for i:=length(a)-2 downto 1 do
//in an attempt to reduce the processing time:
//for i:=length(a)-2 downto length(a) div 3 do
    begin
    tt:=a;
    //delete(tt,length(a)-1,length(a)-i);
    delete(tt,i+1,length(a)-i);
    ht:=a;
    delete(ht,1,length(a)-i);
    if tt=ht then
        begin
        b:=a;
        delete(b,1,i);
        delete(b,length(b)-i,i);
        if pos(tt,b)<>0 then
            begin
            //writeln(tt);
            //halt;
            kq:=tt;
            //break;
            end;
        end;
    end;
writeln(kq);
end.
