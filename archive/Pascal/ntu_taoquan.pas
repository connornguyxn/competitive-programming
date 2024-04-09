var m,n,k,a,b,c:longint;
///////////////////////////////////////
function min(a,b:longint):longint;
    /////////////////
    begin
    if (a < b) then
        exit(a);
    exit(b);
    end;
///////////////////////////////////////
begin
readln(n,m,k);
a := n;
b := m div 2;
c := (m + n - k) div 3;
writeln(min(a, min(b, c)));
end.
