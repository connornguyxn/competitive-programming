type ntoar=array[1..100000000] of boolean;
var nto:ntoar;
    a:array[0..100000000] of int64;
    n,m,i,l,r,t:longint;
//////////////////////////////////////////
procedure sangnto(var a:ntoar);
var i,j:longint;
    begin
    fillchar(a,sizeof(a),true);
    a[1]:=true;
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
/////////////////////////////////////////
begin
readln(n);
sangnto(nto);
m:=0;
//witeln(nto[1]);
//example input:
// 6
// 9 5 -2 6 -1 1
//output:
// 8
for i:=1 to n do
    begin
    read(a[i]);
    a[i]:=a[i]+a[i-1];
    end;
//for i:=1 to n do
//    write(a[i], ' ');
//writeln();
for l:=1 to n-1 do
    begin
    if nto[a[l]-a[l-1]]=false then
        begin
        //writeln('Continue raised due to: nto[a[l]-a[l-1]]=false:', a[l]-a[l-1]);
        continue;
        end;
    for r:=l+1 to n do
        begin
        //0writeln('l=', l, ' r=', r);
        if nto[a[r]-a[r-1]]=false then
            begin
            //writeln('Continue raised due to: nto[a[r]-a[r-1]]=false:', a[r]-a[r-1]);
            continue;
            end;
        t:=a[r-1]-a[l-1];
        //writeln('t=', t);
        if t>m then
            begin
            m:=t;
            //writeln('m:=t=', m);
            end;
        end;
    end;
writeln(m);
end.