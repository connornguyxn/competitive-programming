var a,b,i,d:longint;
///////////////////////////////////////
function f(n,d:longint):longint;
    var i:longint;
    /////////////////
    begin
    if (n = 2) then
        begin
        //writeln();
        exit(d);
        end;
    i := 2;
    while (n mod i = 0) do
        i := i + 1;
    //write(i,' ');
    exit(f(i,d + 1));
    end;
///////////////////////////////////////
begin
readln(a,b);
for i := a to b do
    begin
    //write(i,' = ',i,' ');
    d := d + f(i,1);    
    end;
writeln(d);
end.