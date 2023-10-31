var a,mx,b:string;
    i,j,k:longint;
///////////////////////////////////////
begin
//assign(input,'xoakmax.inp');reset(input);
readln(a);
readln(k);
for j := 1 to k do
    begin
    mx := copy(a,2,length(a) - 1);
    for i := 2 to length(a) do
        begin
        b := a;
        delete(b,i,1);
        writeln(b);
        if (b < mx) then
            mx := b;
        end;
    writeln('mx ',mx);
    a := mx;
    end;
writeln(mx);
end.