var a,b:extended;
    l,r:qword;

begin
readln(a,b);
l:=trunc(a);
r:=trunc(b);
if frac(a)<>0 then
    l:=l+1;
writeln((r-l+1)*(l+r) div 2);
end.