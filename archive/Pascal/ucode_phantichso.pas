type ntoar=array[1..10000000] of boolean;
var nto:ntoar;
    n,i,d:longint;
//////////////////////////////////////////
procedure sangnto(var a:ntoar);
var i,j:longint;
    begin
    fillchar(a,sizeof(a),true);
    a[1]:=false;
    i:=2;
    while i<=trunc(sqrt(sizeof(a))) do
        begin
        while a[i]=false do
            i:=i+1;
        for j:=2 to sizeof(a) div i do
            a[i*j]:=false;
        i:=i+1;
        end;
    end;
////////////////////////////////////////////
begin
sangnto(nto);
readln(n);
for i:=1 to (n div 2) do
    if (nto[n-i]=true) and (nto[i]=true) then
        d:=d+1;
writeln(d);
end.
