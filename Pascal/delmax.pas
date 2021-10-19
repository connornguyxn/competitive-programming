var a,b:ansistring;
    i,j,k:longint;
//////////////////////////////
function stri(a:longint):string;
begin
str(a,stri);
end;
//////////////////////////////
begin
readln(a)
readln(k);
for i:=9 downto 1 do
    begin
    b:='';
    for j:=1 to length(a) do
        begin
        if (a[j]=stri(i)) and (k>0) then
            k:=k-1
        else
            b:=b+a[j];
        end;
    a:=b;
    if k=0 then
        break;
    end;
writeln(a);
end.