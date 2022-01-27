var du:array[0..2] of longint;
    i,n,test,tests,c:longint;
///////////////////////////////////////
function max(a,b:longint):longint;
    begin
    if (a > b) then
        exit(a);
    exit(b)
    end;
////////
function min(a,b:longint):longint;
    begin
    if (a < b) then
        exit(a);
    exit(b)
    end;
///////////////////////////////////////
begin
readln(tests);
for test:=1 to tests do
    begin
    readln(n);
    fillchar(du,sizeof(du),0);
    for i := 1 to (n - 1) do
        begin
        read(c);
        du[c mod 3] := du[c mod 3] + 1;
        end;
    readln(c);
    du[c mod 3] := du[c mod 3] + 1;
    writeln(du[0] + min(du[1],du[2]) + (max(du[1],du[2]) - min(du[1],du[2])) div 3);
    end;
end.