var a:ansistring;
    n:longint;
//////////////////////////////////////
function stri(a:longint):ansistring;
    begin
    str(a,stri);
    end;
////////////////
function int(a:ansistring):longint;
var check:longint;
    begin
    val(a,int,check);
    end;
////////////////
procedure try(a:ansistring;t:longint);
var i:longint;
    begin
    if a = '' then
        begin
        if t = n then
            begin
            writeln('Yes');
            halt;
            end;
        end
    else
        begin
        for i:=1 to length(a) do
            begin
            try(copy(a,1,i),t + int(copy(a,1,i)));
            end;
        end;
    end;
//////////////////////////////////////
begin
readln(a);
readln(n);
try(a,0);
end.