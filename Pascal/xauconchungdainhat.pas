var a,b,c:string;
i,j:longint;

begin
readln(a);
readln(b);
if length(a)>length(b) then
    begin
    c:=a;
    a:=b;
    b:=c;
    end;
c:='';
for i:=1 to length(a)-1 do
    for j:=i+1 to length(a) do
        if (pos(copy(a,i,j-i+1),b)<>0) and (length(copy(a,i,j-i+1))>length(c)) then
            c:=copy(a,i,j-i+1);
writeln(c);
end.