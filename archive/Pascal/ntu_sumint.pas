var i,d:longint;
    n,l,r,scs,t:int64;
    res:array[0..100000000] of int64;
///////////////////////////////////////
function stri(a:int64):ansistring;
    begin
    str(a,stri);
    end;
///////////////////////////////////////
begin
readln(n);
d := -1;
n := n * 2;
for i:=2 to trunc(sqrt(n)) do
    begin
    if (n mod i <> 0) then
        continue;
    t := n div i;
    if ((t + i - 1) mod 2 <> 0) then
        continue;
    r := (t + i - 1) div 2;
    l := t - r;
    d := d + 2;
    res[d] := l;
    res[d+1] := r;
    end;
writeln((d + 1) div 2);
for i:=1 to d do
    begin
    if (i mod 2 <> 0) then
        writeln(res[i],' ',res[i+1]);
    end;
end.