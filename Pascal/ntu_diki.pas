type ar = array[1..1000000] of longint;
var a:ar;
i,p,n,m:longint;
///////////////////////////////////////
function binsearch(a:longint;mg:ar;l,r:longint):longint;
var m:longint;
    begin
    while (l <= r) do
        begin
        m := (l + r) div 2;
        if (a = mg[m]) then
            exit(m);
        if (a < mg[m]) then
            r := m - 1
        else
            l := m + 1;
        end;
    exit(0);
    end;
///////////////////////////////////////
begin
//assign(input,'diki.inp');reset(input);
//assign(output,'diki.out');rewrite(output);
readln(n,m);
for i:=1 to n do
    read(a[i]);
for i:=1 to (n - 1) do
    begin
    p := binsearch(a[i] + m,a,i + 1,n);
    if (p <> 0) then
        begin
        writeln(a[i],' ',a[p]);
        halt;
        end;
    end;
writeln(-1);
end.