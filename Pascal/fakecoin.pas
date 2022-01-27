var d,m:array[1..12] of string;
    c:array[1..8] of longint;
    mk:string;
    i:longint;
///////////////////////////////////////
function inte(a:ansistring):longint;
    var check:longint;
    /////////////////
    begin
    val(a,inte,check);
    end;
///////////////////////////////////////
procedure readinp();
    var s:string;
        i:longint;
    /////////////////
    begin
    for i := 1 to 4 do
        read(c[i]);
    readln(s);
    //writeln(s);
    mk := s[2];
    delete(s,1,3);
    s := s + ' ';
    for i := 5 to 8 do
        begin
        c[i] := inte(copy(s,1,pos(' ',s) - 1));
        delete(s,1,pos(' ',s));
        end;
    end;
///////////////////////////////////////
begin
readinp();
if (mk = '<') then
    begin
    for i := 1 to 4 do
        m[c[i]] := '<';
    for i := 4 to 8 do
        m[c[i]] := '>';
    end
else if (mk = '>') then
    begin
    for i := 1 to 4 do
        m[c[i]] := '>';
    for i := 4 to 8 do
        m[c[i]] := '<';
    end
else
    begin
    for i := 1 to 8 do
        m[c[i]] := '=';
    end;
end.