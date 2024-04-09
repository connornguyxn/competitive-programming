var a,c:ansistring;
    test,tests:longint;
///////////////////////////////////////
begin
assign(input,'ucode_friendship.inp');reset(input);
readln(tests);
for test := 1 to tests do
    begin
    readln(a);
    if (a[1] = '0') then
        c := '1'
    else
        c := '0';
    if (pos('1',a) = 0) then
        begin
        writeln('YES');
        continue;
        end;
    if (pos('0',a) = 0) then
        begin
        writeln('NO');
        continue;
        end;
    while (a[length(a)] = '1') do
        delete(a,length(a),1);
    if (pos(a[1],copy(a,pos(c,a),length(a))) = 0) then
        writeln('YES')
    else
        writeln('NO');
    end;
end.