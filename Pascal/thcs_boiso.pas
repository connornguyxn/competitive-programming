var a:array[1..100000000] of longint;
    c,i,n,t:longint;
/////////////////////////////////////
function stri(a:longint):ansistring;
    /////////////////
    begin
    str(a,stri);
    end;
///////////////////////////////////////
function int(a:ansistring):longint;
    var check:longint;
    /////////////////
    begin
    val(a,int,check);
    end;
///////////////////////////////////////
procedure try(k:longint);
    var i:longint;
    /////////////////
    begin
    if (k = n + 1) then
        begin
        t := 0;
        for i := 1 to n do
            t := t * 10 + a[i];
        if ((t mod c = 0) and (t <> 0)) then
            begin
            writeln(t);
            halt;
            end;
        end
    else
        begin
        for i := 0 to 1 do
            begin
            a[k] := i;
            try(k + 1);
            end;
        end;
    end;
/////////////////////////////////////
begin
readln(c);
n := 8;
try(1);
end.