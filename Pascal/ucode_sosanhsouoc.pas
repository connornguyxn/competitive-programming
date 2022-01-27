var n,i,test,tests,pw,pwl,ex:int64;
///////////////////////////////////////
begin
//assign(input,'ucode_sosanhsouoc.inp');reset(input);
readln(tests);
for test := 1 to tests do
    begin
    readln(n);
    pw := 1;
    ex := 0;
    while (n mod 2 = 0) do
        begin
        ex := ex + 1;
        n := n div 2;
        end;
    pw := pw * (ex + 1);
    i := 3;
    pwl := 1;
    while (i <= trunc(sqrt(n))) do
        begin
        ex := 0;
        while (n mod i = 0) do
            begin
            ex := ex + 1;
            n := n div i;
            end;
        pw := pw * (ex + 1);
        pwl := pwl * (ex + 1);
        i := i + 2;
        end;
    if ((pw - pwl < pwl) or (pw = 1)) then
        begin
        writeln('Odd');
        end
    else if (pw - pwl > pwl) then
        begin
        writeln('Even');
        end
    else
        begin
        writeln('Same');
        end;
    end;
end.