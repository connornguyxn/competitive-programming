//coded w/ <3 by inf1nity
type ntoar=array[1..1000000] of boolean;
var nto:ntoar;
    i,n:longint;
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
///////////////
function sumchar(a:longint):longint;
    begin
    sumchar:=0;
    while a<>0 do
        begin
        sumchar:=sumchar+a mod 10;
        a:=a div 10;
        end;
    end;
////////////////////////////////////////////
begin
readln(n);
sangnto(nto);
for i:=1 to n do
    if nto[i] and nto[sumchar(i)] then
        write(i,' ');
end.
