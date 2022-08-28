var a:array[1..100000000] of longint;
n,i,p:longint;
t,m:int64;
chk:boolean=false;
//////////////////////////////////////////////
begin
assign(input,'ucode_maxseq.inp');reset(input);
assign(output,'ucode_maxseq.out');rewrite(output);
readln(n);
for i:=1 to n do
    begin
    read(a[i]);
    if a[i]>=0 then
        chk:=true;
    end;
if chk=false then
    begin
    m:=0;
    for i:=1 to n do
        if a[i]<m then
            begin
            m:=a[i];
            p:=i;
            end;
    t:=t*0+m;
    m:=0;
    a[p]:=0;
    for i:=1 to n do
        if a[i]<m then
            begin
            m:=a[i];
            p:=i;
            end;
    writeln(t+m)
    end
else
    begin
    for i:=1 to n do
    begin
    if a[i]>=0 then
        t:=t+a[i]
    else
        begin
        if t>m then m:=t;
        t:=0;
        end;
    end;
    writeln(m);
    end;
end.
