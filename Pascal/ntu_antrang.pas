var a:array[1..13] of ansistring;
b,kq,daydu,tuquy:ansistring;
n,i,an,kt,d,j:longint;
////////////////////////////////
//was too lazy to write this every time, so wrote it into a procedure :)
procedure yes;
begin
writeln('YES');
halt;
end;
////////////////////////////////
begin
assign(input,'antrang.inp');reset(input);
assign(output,'antrang.out');rewrite(output);
daydu:='3456789TJQKA2';
tuquy:='CCRRBBGG';
kq:='YES';
for i:=1 to 13 do
    readln(a[i]);
for i:=1 to 13 do
    begin
    if pos(a[i][2],daydu)<>0 then
        delete(daydu,pos(a[i][2],daydu),1);
    if i=13 then yes;
    end;
for i:=1 to 13 do
    begin
    if tuquy='' then yes;
    if pos(a[i][2],tuquy)<>0 then
        delete(tuquy,pos(a[i][2],tuquy),1);
    end;
d:=0;
for i:=1 to 12 do
   for j:=i+1 to 13 do
        begin
        if a[i][1]=a[j][1] then
            begin
            d:=d+1;
            //break;
            end;
        writeln(d);
        if d=5 then yes;
        end;
writeln('NO');
end.
