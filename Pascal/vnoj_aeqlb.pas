var a, b, test, tests: longint;
///////////////////////////////////////
function subtask(a, b: longint): string;
    /////////////////
    begin
    if (a = b) then
        exit('YES');
    if (a > b) then
        exit('NO');
    if (a mod 2 = b mod 2) then
        exit('YES');
    if ((a * 2 <= b) and (b mod 2 = 0)) then
        exit('YES');
    exit('NO');
    end;
///////////////////////////////////////
begin
readln(tests);
for test := 1 to tests do
    begin
    readln(a, b);
    writeln(subtask(a, b));
    end;
end.