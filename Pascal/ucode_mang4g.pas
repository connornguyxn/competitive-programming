var a,b,c,cl,cr,r,t:int64;
///////////////////////////////////////
function max(a,b:int64):int64;
    /////////////////
    begin
    if (a > b) then
        exit(a);
    exit(b);
    end;
///////////////////////////////////////
begin
assign(input,'ucode_mang4g.inp');reset(input);
readln(a);
readln(b);
readln(c);
readln(r);
if (a > b) then
    begin
    t := a;
    a := b;
    b := t;
    end;
cl := c - r;
cr := c + r;
if ((b < cl) or (a > cr)) then
    begin
    writeln(b - a);
    halt;
    end;
t := 0;
if (b > cr) then
    t := t + (b - cr);
if (a < cl) then
    t := t + (cl - a);
writeln(t);
end.