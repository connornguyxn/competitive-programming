var a:ansistring;
d:longint;

begin
assign(input,'detu.inp');reset(input);
assign(output,'detu.out');rewrite(output);
readln(a);
while a[1]='.' do delete(a,1,1);
while a[length(a)]='.' do delete(a,length(a),1);
while length(a)<>0 do
    begin
    d:=d+1;
    if pos('.',a)<>0 then delete(a,pos('.',a),1)
        else break;
    end;
writeln(d);
end.
