var a:array[0..100000000] of longint;
    n,t,i,j:longint;

begin
readln(n);
for i:=1 to n do
    begin
    read(a[i]);
    a[i]:=a[i]+a[i-1];
    end;
for i:=n downto 1 do
    begin
    if a[n] mod n=0 then
        begin
        
        end;
    end;
end.