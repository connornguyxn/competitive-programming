var a,n,i:longint;
    b:ansistring;
///////////////////////////
function tcs(a:ansistring):int64;
var i,e:longint;c:int64;
begin
tcs:=0;
for i:=1 to length(a) do
    begin
        val(a[i],c,e);
        tcs:=tcs+c;
    end;
end;
////////
function stri(number:int64):ansistring;
begin
str(number,stri);
end;
/////////////////////////
begin
readln(a);
while true do
    begin
    a:=a+1;
    n:=a;
    b:='';
    for i:=2 to trunc(sqrt(a)) do
        begin
        while n mod i=0 do
            begin
            b:=b+stri(i);
            n:=n div i;
            end;
        end;
    if n<>1 then
        b:=b+stri(n);
    if tcs(b)=tcs(stri(a)) then
        begin
        writeln(a);
        halt;
        end;
    end;
end.