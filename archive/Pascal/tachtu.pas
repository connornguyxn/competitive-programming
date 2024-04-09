var a,b,x,kq:ansistring;
i,p,j:longint;

begin
assign(input,'tachtu.inp');reset(input);
assign(output,'tachtu.out');rewrite(output);
readln(a);
readln(b);
readln(x);
j:=1;
a:=a+' ';
for i:=1 to length(x) do
    begin
    if x[i]=a[j] then
        begin
        kq:=kq+'1';
        j:=j+1;
        if j=length(a) then break;
        end
    else
        kq:=kq+'2';
    end;

writeln(kq);
end.