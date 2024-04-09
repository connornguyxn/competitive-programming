var a,i,n:longint;
    t,mx:int64;
//////////////////////////////////
begin
assign(input,'ntu_vdseq01.inp');reset(input);
readln(n);
mx := low(int64);
t := 0;
for i := 1 to n do
    begin
    readln(a);
    t := t + a;
    if (a < 0) then
        begin
        if (t > mx) then
            mx := t;
        t := 0;
        end;
    end;
writeln(mx);
end.