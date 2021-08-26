var ch,le:array[1..100000000] of int64;
n,k:int64;
ssc,ssl,i:longint;

begin
assign(input,'sok.inp');reset(input);
assign(output,'sok.out');rewrite(output);
read(n,k);
ssc:=0;ssl:=0;
for i:=1 to n do
    begin
    if i mod 2=0 then
        begin
        ssc:=ssc+1;
        ch[ssc]:=i;
        end
    else
        begin
        ssl:=ssl+1;
        le[ssl]:=i;
        end;
    end;
if k<=ssl then write(le[k])
    else write(ch[k-ssl]);
end.
