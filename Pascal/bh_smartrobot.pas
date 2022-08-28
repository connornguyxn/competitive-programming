type ar = array[1..100000000] of longint;
var n, x, i:longint;
    a:ar;
    t:qword;
///////////////////////////////////////
procedure fill(var a:ar; x, l, r:longint);
    var i:longint;
    /////////////////
    begin
    for i := l to r do
        a[i] := x;
    end;
///////////////////////////////////////
begin
assign(input, 'bh_smartrobot.inp');reset(input);
//assign(output, 'bh_smartrobot.out');rewrite(output);
readln(n, x);
for i := 1 to n do
    read(a[i]);
writeln(a[1]);
i := 1;
while (a[i] mod x = 0) do
    begin
    //writeln(a[i]);
    t := t + a[i];
    fill(a, a[i] div x, n + 1, n + 1 + x);
    n := n + x;
    i := i + 1;
    end;
for i := i to n do
    t := t + a[i];
writeln(t);
end.
