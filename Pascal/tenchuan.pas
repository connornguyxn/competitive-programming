var i:longint;
a,b,inp:ansistring;

begin
assign(input,'tenchuan.inp');reset(input);
assign(output,'tenchuan.out');rewrite(output);
readln(inp);
a:=lowercase(inp);
while a[1]=' ' do
    delete(a,1,1);
while a[length(a)]=' ' do
    delete(a,length(a)-1,1);
while pos('  ',a)<>0 do
    delete(a,pos('  ',a),1);
a:=lowercase(a);
a[1]:=upcase(a[1]);
for i:=1 to length(a) do
    begin
    if a[i]=' ' then
        a[i+1]:=upcase(a[i+1]);
    end;
writeln(a);
end.