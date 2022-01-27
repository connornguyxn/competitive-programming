var a:ansistring;
///////////////////////////////////////
function stri(a:longint):ansistring;
    begin
    str(a,stri);
    end;
/////////////////
function tcs(a:ansistring):int64;
var i,e:longint;
    c:int64;
    begin
    tcs := 0;
    for i:=1 to length(a) do
        begin
        val(a[i],c,e);
        tcs := tcs + c;
        end;
    end;
///////////////////////////////////////
begin
readln(a);
while (length(a) <> 1) do
    begin
    a := stri(tcs(a));
    end;
writeln(a);
end.