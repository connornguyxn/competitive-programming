//coded w/ <3 by connornguyxn
var a,b,c,mx,mn:ansistring;
/////////////////////////////////////////////
function max(a,b:ansistring):ansistring;
    /////////////////
    begin
    if (a > b) then
        exit(a);
    exit(b);
    end;
/////////////////////////////////////////////
procedure try(a,b,c:ansistring);
    /////////////////
    begin
    if ((length(a) = 0) or (length(b) = 0)) then
        begin
        c := c + max(a,b);
        if (c > mx) then
            mx := c;
        if ((c < mn) or (mn = '')) then
            mn := c;
        end
    else
        begin
        try(copy(a,2,length(a) - 1),b,c + a[1]);
        try(a,copy(b,2,length(b) - 1),c + b[1]);
        end;
    end;
/////////////////////////////////////////////
begin
readln(b);
a := copy(b,1,pos(' ',b) - 1);
delete(b,1,pos(' ',b));
mx := '';
mn := '';
try(a,b,'');
writeln(mn);
writeln(mx);
end.
