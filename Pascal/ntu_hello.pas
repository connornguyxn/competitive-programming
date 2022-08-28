var s:ansistring;
    legit:boolean;

begin
assign(input,'ntu_hello.inp');reset(input);
assign(output,'ntu_hello.out');rewrite(output);
readln(s);
legit:=false;
if pos('h',s)<>0 then
    begin
    delete(s,1,pos('h',s));
    if pos('e',s)<>0 then
        begin
        delete(s,1,pos('e',s));
        if pos('l',s)<>0 then
            begin
            delete(s,1,pos('l',s));
            if pos('l',s)<>0 then
                begin
                delete(s,1,pos('l',s));
                if pos('o',s)<>0 then
                    legit:=true;
                end;
            end;
        end;
    end;
if legit then
    writeln('YES')
else
    writeln('NO');
end.
