var a,b,c,d,ts,ms:int64;
///////////////////////////////////////
function ucln(a,b:int64):int64;
    var r:int64;
    /////////////////
    begin
    while (b <> 0) do
        begin
        r := a mod b;
        a := b;
        b := r;
        end;
    exit(a);
    end;
///////////////////////////////////////
function bcnn(a,b:int64):int64;
    /////////////////
    begin
    exit(a * b div ucln(a,b));
    end;
///////////////////////////////////////
begin
readln(a,b);
readln(c,d);
ms := bcnn(b,d);
ts := a * (ms div b) + c * (ms div d);
writeln(ts div ucln(ts,ms),' ',ms div ucln(ts,ms));
end.