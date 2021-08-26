var i,n,d:longint;
x,y,j:int64;
a,b:ansistring;
//////////////////////////////////////
procedure fill(a,b:ansistring);
begin
while length(a)<>length(b) do
    begin
    if length(a)<length(b) then
        a:=a+'0'
    else
        b:=b+'0';
    end;
end;
//////////////////
function reverse(a:ansistring):ansistring;
var i:longint;
begin
for i:=length(a) downto 1 do
    reverse:=reverse+a[i];
end;
///////////////////////////////////////
begin
assign(input,'cntpalin.inp');reset(input);
assign(output,'cntpalin.out');rewrite(output);
readln(n);
for i:=1 to n do
    begin
    readln(x,y);
    str(x,a);
    str(y,b);
    while x<y do
        begin
        fill(a,b);
        if reverse(a)=a then d:=d+1;
        x:=x+1;
        end;
    writeln(d);
    end;

end.
