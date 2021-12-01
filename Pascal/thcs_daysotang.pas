var a:array[1..100000000] of longint;
    i,j,n,mx,d:longint;
    legit:boolean;
    k:ansistring;

function stri(number:int64):ansistring;
    begin
    str(number,stri);
    end;

begin
readln(n);
for i:=1 to n do
    read(a[i]);
mx:=a[1];
for i:=2 to n-1 do
    begin
    if a[i]>mx then
        begin
        mx:=a[i];
        end;
    legit:=true;
    for j:=i+1 to n do
        begin
        if a[j]<mx then
            begin
            legit:=false;
            break;
            end;
        end;
    if legit=true then
        begin
        d:=d+1;
        k:=k+stri(i)+' ';
        end;
    end;
writeln(d);
writeln(k);
end.