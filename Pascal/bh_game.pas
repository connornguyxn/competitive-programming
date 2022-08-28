var a:array[0..100000000] of longint;
    i,n,d,tests,test,mx:longint;
///////////////////////////////////////
begin
readln(tests);
for test := 1 to tests do
    begin
    readln(n);
    d := 0;
    read(mx);
    for i := 2 to n do
        begin
        read(a[i]);
        if (a[i] < mx) then
            begin
            d := d + 1;
            mx := a[i];
            end;
        end;
    if (d mod 2 = 1) then
        writeln('AN')
    else
        writeln('BINH');
    end;
end.