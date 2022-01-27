var a,b,v,r,d:longint;
///////////////////////////////////////
begin
readln(a,b,v);
if (v <= a) then
    begin
    writeln(1);
    halt;
    end;
v := v - b;
if (v mod (a - b) = 0) then
    writeln(v div (a - b))
else
    writeln(v div (a - b) + 1);
end.