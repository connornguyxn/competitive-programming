procedure selectionsort(var a:array of longint; n:longint);
var i,j:longint;
begin
for i:=1 to n-1 do
    for j:=i+1 to n do
        if (a[j] > a[j-1]) then
            begin
            a[j]:=a[j]+a[j-1];
            a[j-1]:=a[j]-a[j-1];
            a[j]:=a[j]-a[j-1];
            end;
end;