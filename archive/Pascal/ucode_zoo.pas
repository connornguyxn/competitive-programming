var a:array[1..100000000] of ansistring;
mm:ansistring;
i,j,n,d:longint;

begin
readln(n);
for i:=1 to n do
    begin
    readln(a[i]);
    while pos(' ',a[i])<>0 do
        delete(a[i],1,pos(' ',a[i]));
    a[i]:=lowercase(a[i]);
    end;
for i:=1 to n do
    for j:=i+1 to n do
        if ord(a[j][1])<ord(a[j-1][1]) then
            begin
            mm:=a[i];
            a[i]:=a[j];
            a[j]:=mm;
            end;
for i:=1 to n do
    begin
    if a[i]=a[i+1] then
        d:=d+1
    else
        begin
        writeln(a[i],' | ',d+1);
        d:=0;
        end;
    end;
end.
