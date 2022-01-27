var a:string;
    i,n,j,t:longint;
///////////////////////////////////////
function stri(a:longint):ansistring;
    /////////////////
    begin
    str(a,stri);
    end;
///////////////////////////////////////
function intr(a:string):longint;
    var check:longint;
    /////////////////
    begin
    val(a,intr,check);
    end;
///////////////////////////////////////
function mu(a,n:longint):longint;
    var i:longint;
    /////////////////
    begin
    mu := 1;
    for i := 1 to n do
        mu := mu * a;
    end;
///////////////////////////////////////
begin
readln(n);
for i := 1 to n do
    begin
    a := stri(i);
    t := 1;
    for j := 1 to length(a) do
        t := t + mu(intr(a[j]),length(a));
    if (t = i) then
        writeln(i);
    end;
end.