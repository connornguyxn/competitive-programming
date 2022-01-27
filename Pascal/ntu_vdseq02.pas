var a:array[0..100000000] of longint;
    i,l,r,n,k,mxc,tmp:longint;

begin
readln(n,k);
for i := 1 to n do
    begin
    readln(a[i]);
    a[i] := a[i] mod k + a[i - 1];
    end;
mxc := 0;
for l := 1 to (n - 1) do
    begin
    if (n - l + 1 <= mxc) then
        break;
    tmp := mxc;
    for r := (l + tmp + 1) to n do
        if ((a[r] - a[l - 1]) mod k = 0) then
            mxc := r - l + 1;
    end;
writeln(mxc);
end.