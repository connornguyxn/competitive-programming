var n:longint;
    a:string;
///////////////////////////////////////
function cstr(a:longint):string;
    begin
    str(a,cstr);
    end;
///////////////////////////////////////
procedure try(a:string;n:longint);
    var i:longint;
    /////////////////
    begin
    if (n = 0) then
        begin
        writeln(a);
        end
    else
        begin
        for i := 1 to n do
            begin
            //writeln('n',n);
            try(a + cstr(i) + ' ',n - i);
            end;
        end;
    end;
///////////////////////////////////////
begin
readln(n);
try('',n);
end.