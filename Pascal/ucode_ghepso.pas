type ar = array[1..1000000] of string;
var a:ar;
    d,i,n:longint;
    s:string;
//////////////////////////////////////
procedure qsort(var a:ar;l,r:longint);
var i,j:longint;
    x,tg:string;
    begin
    i := l;
    j := r;
    x := a[(i + j) div 2];
    while (i <= j) do
        begin
        while (a[i] < x) do
            i := i + 1;
        while (a[j] > x) do
            j := j - 1;
        if (i <= j) then
            begin
            tg := a[i];
            a[i] := a[j];
            a[j] := tg;
            i := i + 1;
            j := j - 1;
            end;
        end;
    if (i < r) then
        qsort(a,i,r);
    if (j > l) then
        qsort(a,l,j);
    end;
///////////////////////////////////////
begin
readln(s);
readln(s);
s := s + ' ';
n := 0;
while (pos(' ',s) <> 0) do
    begin
    n := n + 1;
    a[n] := copy(s,1,pos(' ',s) - 1);
    delete(s,1,pos(' ',s));
    end;
qsort(a,1,n);
for i := n downto 1 do
    write(a[i]);
end.