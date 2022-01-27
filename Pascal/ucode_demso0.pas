var a:ansistring;
    d:int64;
///////////////////////////////////////
begin
readln(a);
d := 0;
while (a[length(a)] = '0') do
    delete(a,length(a),1);
while (pos('0',a) <> 0) do
    begin
    d := d + 1;
    delete(a,pos('0',a),1);
    end;
writeln(d);
end.