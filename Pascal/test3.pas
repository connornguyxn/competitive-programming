const MAXN = 20;
var f: text;
    n: integer;
    a: array [1..MAXN] of integer;
    dem: integer;


procedure Nhap;
begin
        readln(f, n);
        close(f);
        dem:= 0;
end;

procedure InKQ;
var i: integer;
begin
        inc(dem);
        write(f, dem:3, ': ');
        for i:= 1 to n do
                write(f, a[i]);
        writeln(f);
end;

procedure Try2(i: integer); // dien gia tri cho vi tri thu i
var j: integer;
begin
        for j:= 0 to 1 do
        begin
                a[i]:= j;
                if i = n then InKQ
                        else Try2(i+1);
        end;
end;

BEGIN
        Nhap;
        Try2(1);
        close(f);
END.