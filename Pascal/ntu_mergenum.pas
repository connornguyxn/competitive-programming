var a,b,c,d:ansistring;
i,j:longint;

begin
assign(input,'ntu_mergenum.inp');reset(input);
assign(output,'ntu_mergenum.out');rewrite(output);
readln(b);
a:=copy(b,1,pos(' ',b)-1);
delete(b,1,pos(' ',b));
i:=1;
j:=1;
c:='';
while (i<>length(a)+1) and (j<>length(b)+1) do
    begin
    if a[i]<b[j] then
        begin
        c:=c+a[i];
        i:=i+1;
        end
    else
        begin
        c:=c+b[j];
        j:=j+1;
        end;
    end;
d:=copy(a,i,length(a))+copy(b,j,length(b));
if c+d<d+c then
    writeln(c+d)
else
    writeln(d+c);
i:=1;
j:=1;
c:='';
while (i<>length(a)+1) and (j<>length(b)+1) do
    begin
    if a[i]>b[j] then
        begin
        c:=c+a[i];
        i:=i+1;
        end
    else
        begin
        c:=c+b[j];
        j:=j+1;
        end;
    end;
d:=copy(a,i,length(a))+copy(b,j,length(b));
if c+d>d+c then
    writeln(c+d)
else
    writeln(d+c);
end.
