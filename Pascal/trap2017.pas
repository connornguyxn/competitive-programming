var x,y,minx,miny,maxx,maxy:int64;
n,i:longint;

begin
assign(input,'trap.inp');reset(input);
assign(output,'trap.out');rewrite(output);
readln(n);
for i:=1 to n do
    begin
    readln(x,y);
    if i=1 then
        begin
        minx:=x;
        maxx:=x;
        miny:=y;
        maxy:=y;
        end
    else
        begin
        if x<minx then minx:=x;
        if x>maxx then maxx:=x;
        if y<miny then miny:=y;
        if y>maxy then maxy:=y;
        end;
    end;
writeln(minx,' ',maxy,' ',maxx,' ',miny)
end.
