var n,i:longint;
    uc,a:int64;
///////////////////////////////////////
function ucln(a,b:int64):int64;
var r:int64;
    begin
    while (b <> 0) do
        begin
        r := a mod b;
        a := b;
        b := r;
        end;
    ucln := a;
    end;
///////////////////////////////////////
begin
readln(n);
read(uc);
for i := 2 to n do
    begin
    read(a);
    uc := ucln(uc,a);
    end;
writeln(uc * n);
end.