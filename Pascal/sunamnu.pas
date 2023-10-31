var m,n,nam,nu:qword;a:ansistring;

begin
assign(input,'namnu.inp');reset(input);
assign(output,'namnu.out');rewrite(output);
readln(m,n);
readln(a);
nam:=0;nu:=0;
while (pos('11',a)<>0) and (pos('00',a)<>0) do
    begin
    if pos('11',a)<>0 then
        begin
        nam:=nam+1;
        insert('2',a,pos('11',a)+1);
        end;
    if pos('00',a)<>0 then
        begin
        nu:=nu+1;
        insert('2',a,pos('00',a)+1);
        end;
    end;
writeln(nam-nu);
end.
