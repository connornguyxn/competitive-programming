var a,m:qword;


begin
assign(input,'ucode_factoryprod.inp');reset(input);
assign(output,'ucode_factoryprod.out');rewrite(output);
readln(a,m);
while a<=100000 do
    begin
    if a mod m=0 then
        begin
        writeln('Yes');
        halt;
        end;
    a:=a+(a mod m);
    end;
writeln('No')
end.