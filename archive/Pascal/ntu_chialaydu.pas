var du:array[0..100000000] of boolean;
    i,n,k,d:longint;
    a:int64;

begin
readln(n,k);
fillchar(du,sizeof(du),false);
d:=0;
for i:=1 to n do
    begin
    read(a);
    if du[a mod k]=false then
        begin
        d:=d+1;
        du[a mod k]:=true;
        end;
    end;
writeln(d);
end.