var d,m:longint;
///////////////////
function days(m:longint):longint;
begin
if m in [1,3,5,7,8,10,12] then
    exit(31)
else
    if m in [4,6,9,11] then
        exit(30)
    else
        exit(28);
end;
////////////////
begin
readln(m);
readln(d);
writeln(m+(d+1) div days(m));
writeln((d+1) mod days(m));
end.
