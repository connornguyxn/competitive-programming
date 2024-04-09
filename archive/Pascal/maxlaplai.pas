var max,d,l:longint;
inp,a:ansistring;

begin
assign(input,'maxlaplai.inp');reset(input);
assign(output,'maxlaplai.out');rewrite(output);
readln(inp);
max:=1;
a:=inp;
while a<>'' do
    begin
    l:=length(copy(a,1,pos(' ',a)));
    while pos(' ',a)<>0 do
        begin
        if length(copy(a,1,pos(' ',a)))=l then
            d:=d+1;
        delete(a,1,pos(' ',a));
        end;

    end;
writeln(max);
end.
