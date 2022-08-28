var a,i,n,uc:longint;
///////////////////////////////////////
function ucln(a,b:longint):longint;
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
read(a);
uc := ucln(uc,a);
for i := 2 to n do
    begin
    read(a);
    uc := ucln(uc,a);
    end;
writeln(uc * n);
end.
