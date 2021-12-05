var n,i:longint;
t:ansistring;
////////////
function stri(number:int64):ansistring;
    begin
    str(number,stri);
    end;
///////////
begin
readln(n);
i:=2;
while i<=trunc(sqrt(n)) do
    begin
    while n mod i=0 do
        begin
        t:=t+stri(i)+'*';
        n:=n div i;
        end;
    i:=i+1;
    end;
if n<>1 then
    t:=t+stri(n)
else
    delete(t,length(t),1);
writeln(t);
end.