var n,i,a1,a2,test,tests:longint;
///////////////////////////////////////
function lcm(a,b:int64):int64;
    var r:int64;
    /////////////////
    begin
    lcm := a * b;
    while (b <> 0) do
        begin
        r := a mod b;
        a := b;
        b := r;
        end;
    lcm := lcm div a;
    end;
///////////////////////////////////////
begin
readln(tests);
for test := 1 to tests do
    begin
    readln(n);
    read(a1);
    write(a1,' ');
    for i := 2 to n do
        begin
        read(a2);
        write(lcm(a1,a2),' ');
        a1 := a2;
        end;
    writeln(a2);
    end;
end.