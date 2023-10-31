type ar = array[1..1000000] of longint;
var a:ar;
n,i,m:longint;
////////////////////////////////////
function binsearch(a:longint;mg:ar;l,r:longint):longint;
    var m:longint;
    /////////////////
    begin
    while (l <= r) do
        begin
        m := (l+r) div 2;
        if (a < mg[m]) then
            r := m - 1
        else if (a > mg[m]) then
            l := m + 1
        else
            exit(m);
        end;
    exit(0);
    end;
////////////////////////////////////
begin
assign(input,'binsearch.inp');reset(input);
//assign(output,'binsearch.out');rewrite(output);
readln(n,m);
for i:=1 to n do
    read(a[i]);
writeln(binsearch(m,a,1,n));
end.
