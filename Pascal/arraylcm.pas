const modf = 1000000007;
var a,res:qword;
    i,n:longint;
///////////////////////////////////////
function lcm(a,b:qword):qword;
    var r:qword;
    /////////////////
    begin
    lcm := a * b;
    while (b > 0) do
        begin
        r := a mod b;
        a := b;
        b := r;
        end;
    exit(lcm div a);
    end;
///////////////////////////////////////
begin
assign(input,'arraylcm.inp');reset(input);
readln(n);
res := 1;
for i := 1 to n do
    begin
    read(a);
    res := lcm(res,a);
    end;
writeln(res mod modf);
end.