var a,i,n,t,mx,td,test,tests,l:longint;
///////////////////////////////////////
begin
assign(input,'ucode_justeatit.inp');reset(input);
readln(tests);
for test := 1 to tests do
    begin
    readln(n);
    t := 0;
    td := 0;
    mx := 0;
    l := 0;
    for i := 1 to n do
        begin
        read(a);
        t := t + a;
        if (a < 0) then
            begin
            if ((td > mx)and (l <> n)) then
                mx := td;
            
            td := 0;
            write(a,' ');
            end
        else if (a > 0) then
            begin
            td := td + a;
            l := l + 1;            
            end;
        end;
    if ((td > mx) and (td <> t)) then
        mx := td;
    if (t > mx) then
        writeln('YES')
    else
        writeln('NO');
    end;
end.