var uc:int64;
    a:array[0..100000000] of int64;
    i,n,d:longint;
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
assign(input,'thpt_divide.inp');reset(input);
readln(n);
for i := 1 to n do
    read(a[i]);
uc := a[1];
d := 0;
i := 1;
for i := 1 to n do
    begin
    uc := ucln(a[i],uc);
    if (uc = 1) then
        begin
        d := d + 1;
        uc := a[i + 1];
        end;
    end;
if (d = 0) then
    writeln(-1)
else
    writeln(d);
end.