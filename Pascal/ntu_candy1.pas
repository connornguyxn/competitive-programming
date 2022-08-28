const modf = 100003;
var n,k,q:qword;
///////////////////////////////////////
function pow(n,k:qword):qword;
    /////////////////
    begin
    pow := 1;
    while (k > 0) do
        begin
        if (k mod 2 = 1) then
            pow := pow * n mod modf;
        n := sqr(n mod modf) mod modf;
        k := k div 2;
        end;
    end;
///////////////////////////////////////
begin
readln(n,k);
for i := 1 o
end.