var a,kq:ansistring;
l,r:longint;
////////////////////
begin
readln(a);
l:=1;
r:=length(a);
kq:='Just a joke';
while l<=length(a) div 3 do
    begin
    if (copy(a,1,l)=copy(a,r,length(a)-r+1)) and (pos(copy(a,1,l),copy(a,l,r-l+1))<>0) then
        begin
        kq:=copy(a,1,l);
        break;
        end;
    l:=l+1;
    r:=r-1;
    end;
writeln(kq);
end.
