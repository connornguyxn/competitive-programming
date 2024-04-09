var i:longint;
    n:int64;
    a:array[0..100000000] of longint;
///////////////////////////////////////
function rev(a:ansistring):ansistring;
var i,kt:longint;
    begin
    rev := '';
    for i:=1 to length(a) do
        rev:=a[i]+rev;
    end;
/////////////////
function stri(a:longint):ansistring;
    begin
    str(a,stri);
    end;
/////////////////
function int(a:ansistring):longint;
var check:longint;
    begin
    val(a,int,check);
    end;
///////////////////////////////////////
begin
readln(n);
if (n = 1) then
    begin
    writeln(1);
    halt;
    end;
a[0] := 1;
for i:=1 to 81 do
    begin
    a[i] := int(rev(stri(a[i-1]))) + 2;
    end;
a[0] := 10;
writeln(a[(n - 1) mod 81]);
end.