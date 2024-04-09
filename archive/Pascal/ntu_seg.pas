var a:array[0..100000000] of longint;
    n,t,i,j,d:longint;
/////////////////////////////////////////
begin
//assign(input,'ntu_seg.inp');reset(input);
readln(n);
for i:=1 to n do
    begin
    readln(a[i]);
    a[i]:=a[i]+a[i-1];
    end;
for i:=n downto 1 do
    begin
    if a[n] mod i=0 then
        begin
        t:=a[n] div i;
        d:=1;
        for j:=1 to n do
            begin
            if a[j]=t*d then
                begin
                d:=d+1;
                end;
            end;
        if d-1=i then
            begin
            writeln(d-1);
            halt;
            end;
        end;
    end;
end.