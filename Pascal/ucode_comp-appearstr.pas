var a,chrs,c:ansistring;
i,j,d:longint;
///////////////////////////////////
begin
assign(input,'ucode_comp_appearstr.inp');reset(input);
assign(output,'ucode_comp_appearstr.out');rewrite(output);
chrs:='ABCDEFGHIJKLMNOPQRSTUVWXYZ';
readln(a);
for i:=0 to 9 do
    begin
    str(i,c);
    d:=0;
    while pos(c,a)<>0 do
        begin
        d:=d+1;
        delete(a,pos(c,a),1);
        end;
    if d<>0 then writeln(c,' ',d);
    end;

for j:=1 to 2 do
    begin
    for i:=1 to length(chrs) do
        begin
        d:=0;
        while pos(chrs[i],a)<>0 do
            begin
            d:=d+1;
            delete(a,pos(chrs[i],a),1);
            end;
        if d<>0 then writeln(chrs[i],' ',d);
        end;
    chrs:=lowercase(chrs);
    end;
end.

