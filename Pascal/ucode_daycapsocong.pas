var a,b,c,res,i:int64;
///////////////////////
function max(a,b:int64):int64;
    begin
    if (a > b) then
        exit(a);
    exit(b)
    end;
////////
function min(a,b:int64):int64;
    begin
    if (a < b) then
        exit(a);
    exit(b)
    end;
////////////////////////
begin
readln(a,b,c);
if ((b < a) and (b < c)) then
    begin
    writeln((a + c) div 2 - b );
    end
else
    begin
    writeln(abs(min(b - a,c - b) - max(b - a,c - b)));
    end;
end.