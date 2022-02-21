var mk:array[0..100000000] of boolean;
    i,n,t,m:longint;
    res:ansistring;
    neg:boolean;
///////////////////////////////////////
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
begin
readln(t,m);
neg := (t * m < 0);
if (t mod m = 0) then
    begin
    if (neg) then
        write('-');
    writeln(t div m);
    halt;
    end;
t := abs(t);
m := abs(m);
res := stri(t mod m) + '.';

end.