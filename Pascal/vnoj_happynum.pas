var tc,tcs,n:longint;
///////////////////////////////////////
function subtask1(n:longint):string;
    var empt,p:array[0..1000000] of boolean;
        s:qword;
    /////////////////
    begin
    p := empt;
    while (true) do
        begin
        if (n = 1) then
            exit('YES');
        if (p[n]) then
            exit('NO');
        p[n] := true;
        s := 0;
        while (n > 0) do
            begin
            s := s + sqr(n mod 10);
            n := n div 10;
            end;
        n := s;
        end;
    end;
///////////////////////////////////////
begin
assign(input,'vnoj_happynum.inp');reset(input);
//assign(output,'vnoj_happynum.out');rewrite(output);
readln(tcs);
for tc := 1 to tcs do
    begin
    readln(n);
    writeln(subtask1(n));
    end;
end.