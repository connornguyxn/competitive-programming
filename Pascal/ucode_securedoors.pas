var a,b,rec,c:ansistring;
n,i:longint;

begin
assign(input,'ucode_securedoors.inp');reset(input);
assign(output,'ucode_securedoors.out');rewrite(output);
readln(n);
for i:=1 to n do
    begin
    readln(a);
    if copy(a,1,5)='entry' then
        begin
        c:=copy(a,7,length(a)-6);
        write(c,' entered');
        if pos(c,rec)=0 then
            begin
            rec:=rec+' '+c;
            writeln();
            end
        else
            writeln(' (ANOMALY)');
        end
    else
        begin
        c:=copy(a,6,length(a)-5);
        write(c,' exited');
        if pos(c,rec)=0 then
            writeln(' (ANOMALY)')
        else
            begin
            delete(rec,pos(c,rec)-1,length(c)+1);
            writeln();
            end;
        end;
    end;
end.