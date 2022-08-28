var u,d,l,r,test,tests,n:longint;
    u,d,l,r:array[1..2] of longint;
    kq:string;
///////////////////////////////////////
function max(a,b:longint):longint;
    /////////////////
    begin
    if (a > b) then
        exit(a);
    exit(b);
    end;
///////////////////////////////////////
begin
assign(input,'ucode_lattuongnha.inp');reset(input);
readln(tests);
for test := 1 to tests do
    begin
    readln(n,u,r,d,l);
    u := max(0,u - (n - 2));
    r := max(0,r - (n - 2));
    d := max(0,d - (n - 2));
    l := max(0,l - (n - 2));
    if ((l > 0) and (u > 0)) then
        begin
        l := l - 1;
        u := u - 1;
        end;
    if ((u > 0) and (r > 0)) then
        begin
        u := u - 1;
        r := r - 1;
        end;
    if ((r > 0) and (d > 0)) then
        begin
        r := r - 1;
        d := d - 1;
        end;
    if ((d > 0) and (l > 0)) then
        begin
        d := d - 1;
        l := l - 1
        end;
    writeln(u,r,d,l);
    if ((u < 0) or (d < 0) or (l < 0) or (r < 0)) then
        writeln('NO')
    else
        writeln('YES');
    end;
end.