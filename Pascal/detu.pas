var a:ansistring;
d:longint=0;

begin
assign(input,'detu.inp');reset(input);
assign(output,'detu.out');rewrite(output);
readln(a);
while a[length(a)]='.' do
    delete(a,length(a),1);
while a[1]='.' do
    delete(a,1,1);
while length(a)<>0 do
    begin
    if length(copy(a,1,pos('.',a)))<>1 then d:=d+1;
    delete(a,1,pos('.',a));
    end;
writeln(d);
end.
