var i,n,a:longint;
    b:ansistring;
//////////////////////////////////////////
function dec(a:ansistring):longint;
var i,j,b,kt:longint;
t:longint;
begin
dec:=0;
for i:=length(a) downto 1 do
    begin
    t:=1;
    for j:=1 to length(a)-i do
        begin
        t:=t*2;
        end;
    val(a[i],b,kt);
    dec:=dec+(b*t);
    end;
end;
/////
function bin(a:longint):ansistring;
var b:ansistring;
begin
while (a <> 0) do
    begin
    str((a mod 2),b);
    bin:=b+bin;
    a:=a div 2;
    end;
end;
//////////////////////////////////////////
begin
//assign(input,'ntu_negative.inp');reset(input);
//assign(output,'ntu_negative.out');rewrite(output);
readln(n);
for i:=1 to n do
    begin
    readln(a);
    if (a = 0) then
        begin
        writeln(1);
        continue;
        end;
    b:=bin(a);
    while (pos('0',b) <> 0) do
        begin
        b[pos('0',b)]:='1';
        end;
    writeln(dec(b)-a);
    end;
end.
